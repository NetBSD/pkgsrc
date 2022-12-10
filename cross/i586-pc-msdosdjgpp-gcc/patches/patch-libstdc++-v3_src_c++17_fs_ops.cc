$NetBSD: patch-libstdc++-v3_src_c++17_fs_ops.cc,v 1.1 2022/12/10 10:44:59 js Exp $

From https://gcc.gnu.org/pipermail/gcc-patches/2021-October/580752.html

--- ./libstdc++-v3/src/c++17/fs_ops.cc.orig	2021-07-28 06:55:09.336315933 +0000
+++ ./libstdc++-v3/src/c++17/fs_ops.cc
@@ -360,7 +360,7 @@ fs::copy(const path& from, const path& t
     }
   if (is_other(f) || is_other(t))
     {
-      ec = std::make_error_code(std::errc::not_supported);
+      ec = std::make_error_code(std::errc::invalid_argument);
       return;
     }
   if (is_directory(f) && is_regular_file(t))
@@ -419,7 +419,7 @@ fs::copy(const path& from, const path& t
   else
     ec.clear();
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -442,7 +442,7 @@ fs::copy_file(const path& from, const pa
   return do_copy_file(from.c_str(), to.c_str(), copy_file_options(options),
 		      nullptr, nullptr, ec);
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
   return false;
 #endif
 }
@@ -591,7 +591,7 @@ namespace
 	created = true;
       }
 #else
-    ec = std::make_error_code(std::errc::not_supported);
+    ec = std::make_error_code(std::errc::function_not_supported);
 #endif
     return created;
   }
@@ -639,7 +639,7 @@ fs::create_directory(const path& p, cons
     }
   return create_dir(p, static_cast<perms>(st.st_mode), ec);
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_function_not_supported);
   return false;
 #endif
 }
@@ -660,7 +660,7 @@ fs::create_directory_symlink(const path&
 			     error_code& ec) noexcept
 {
 #ifdef _GLIBCXX_FILESYSTEM_IS_WINDOWS
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #else
   create_symlink(to, new_symlink, ec);
 #endif
@@ -692,7 +692,7 @@ fs::create_hard_link(const path& to, con
   else
     ec.assign((int)GetLastError(), system_category());
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -716,7 +716,7 @@ fs::create_symlink(const path& to, const
   else
     ec.clear();
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -784,7 +784,7 @@ fs::current_path(error_code& ec)
     }
 #endif  // __GLIBC__
 #else   // _GLIBCXX_HAVE_UNISTD_H
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   return p;
 }
@@ -807,7 +807,7 @@ fs::current_path(const path& p, error_co
   else
     ec.clear();
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -847,7 +847,7 @@ fs::equivalent(const path& p1, const pat
     {
       if (is_other(s1) && is_other(s2))
 	{
-	  ec = std::make_error_code(std::errc::not_supported);
+	  ec = std::__unsupported();
 	  return false;
 	}
       ec.clear();
@@ -905,7 +905,7 @@ fs::equivalent(const path& p1, const pat
     ec.clear();
   return false;
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   return false;
 }
@@ -936,7 +936,7 @@ namespace
       ec.clear();
       return f(st);
 #else
-      ec = std::make_error_code(std::errc::not_supported);
+      ec = std::make_error_code(std::errc::function_not_supported);
       return deflt;
 #endif
     }
@@ -961,10 +961,10 @@ fs::file_size(const path& p, error_code&
       if (s.type == file_type::directory)
 	ec = std::make_error_code(std::errc::is_a_directory);
       else
-	ec = std::make_error_code(std::errc::not_supported);
+	ec = std::__unsupported();
     }
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   return -1;
 }
@@ -986,7 +986,7 @@ fs::hard_link_count(const path& p, error
   return do_stat(p, ec, std::mem_fn(&stat_type::st_nlink),
 		 static_cast<uintmax_t>(-1));
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
   return static_cast<uintmax_t>(-1);
 #endif
 }
@@ -1034,7 +1034,7 @@ fs::last_write_time(const path& p, error
 		 },
 		 file_time_type::min());
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
   return file_time_type::min();
 #endif
 }
@@ -1080,7 +1080,7 @@ fs::last_write_time(const path& p,
   else
     ec.clear();
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -1129,7 +1129,7 @@ fs::permissions(const path& p, perms prm
     err = errno;
 #else
   if (nofollow && is_symlink(st))
-    ec = std::make_error_code(std::errc::not_supported);
+    ec = std::__unsupported();
   else if (posix::chmod(p.c_str(), static_cast<posix::mode_t>(prms)))
     err = errno;
 #endif
@@ -1214,7 +1214,7 @@ fs::path fs::read_symlink(const path& p,
     }
   while (true);
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   return result;
 }
@@ -1442,7 +1442,7 @@ fs::resize_file(const path& p, uintmax_t
 void
 fs::resize_file(const path& p, uintmax_t size, error_code& ec) noexcept
 {
-  if (size > static_cast<uintmax_t>(std::numeric_limits<off_t>::max()))
+  if (size > static_cast<uintmax_t>(std::numeric_limits<posix::off_t>::max()))
     ec.assign(EINVAL, std::generic_category());
   else if (posix::truncate(p.c_str(), size))
     ec.assign(errno, std::generic_category());
