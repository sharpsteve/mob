#pragma once

#include "utility.h"

namespace mob
{

class context;

class op
{
public:
	enum flags
	{
		noflags = 0,
		optional = 1
	};

	static void touch(const fs::path& p);
	static void create_directories(const fs::path& p, const context* cx=nullptr);
	static void delete_directory(const fs::path& p, flags f=noflags, const context* cx=nullptr);
	static void delete_file(const fs::path& p, flags f=noflags, const context* cx=nullptr);
	static void remove_readonly(const fs::path& first, const context* cx=nullptr);
	static void rename(const fs::path& src, const fs::path& dest);
	static void move_to_directory(const fs::path& src, const fs::path& dest_dir);

	static void copy_file_to_dir_if_better(
		const fs::path& file, const fs::path& dest_dir, flags f=noflags);

private:
	static void do_touch(const fs::path& p);
	static void do_create_directories(const fs::path& p, const context* cx=nullptr);
	static void do_delete_directory(const fs::path& p, const context* cx=nullptr);
	static void do_delete_file(const fs::path& p, const context* cx=nullptr);
	static void do_copy_file_to_dir(const fs::path& f, const fs::path& d);
	static void do_remove_readonly(const fs::path& p, const context* cx=nullptr);
	static void do_rename(const fs::path& src, const fs::path& dest);
	static void check(const fs::path& p, const context* cx=nullptr);
};

}	// namespace
