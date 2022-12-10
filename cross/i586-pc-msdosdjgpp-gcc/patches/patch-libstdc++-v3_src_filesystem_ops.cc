$NetBSD: patch-libstdc++-v3_src_filesystem_ops.cc,v 1.1 2022/12/10 10:44:59 js Exp $

From https://gcc.gnu.org/pipermail/gcc-patches/2021-October/580752.html

--- ./libstdc++-v3/src/filesystem/ops.cc.orig	2021-07-28 06:55:09.340315989 +0000
+++ ./libstdc++-v3/src/filesystem/ops.cc
@@ -293,7 +293,7 @@ fs::copy(const path& from, const path& t
     }
   if (is_other(f) || is_other(t))
     {
-      ec = std::make_error_code(std::errc::not_supported);
+      ec = std::make_error_code(std::errc::invalid_argument);
       return;
     }
   if (is_directory(f) && is_regular_file(t))
@@ -372,7 +372,7 @@ fs::copy_file(const path& from, const pa
   return do_copy_file(from.c_str(), to.c_str(), copy_file_options(options),
 		      nullptr, nullptr, ec);
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
   return false;
 #endif
 }
@@ -491,7 +491,7 @@ namespace
 	created = true;
       }
 #else
-    ec = std::make_error_code(std::errc::not_supported);
+    ec = std::make_error_code(std::errc::function_not_supported);
 #endif
     return created;
   }
@@ -539,7 +539,7 @@ fs::create_directory(const path& p, cons
     }
   return create_dir(p, static_cast<perms>(st.st_mode), ec);
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
   return false;
 #endif
 }
@@ -560,7 +560,7 @@ fs::create_directory_symlink(const path&
 			     error_code& ec) noexcept
 {
 #ifdef _GLIBCXX_FILESYSTEM_IS_WINDOWS
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #else
   create_symlink(to, new_symlink, ec);
 #endif
@@ -592,7 +592,7 @@ fs::create_hard_link(const path& to, con
   else
     ec.assign((int)GetLastError(), system_category());
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -616,7 +616,7 @@ fs::create_symlink(const path& to, const
   else
     ec.clear();
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -683,7 +683,7 @@ fs::current_path(error_code& ec)
     }
 #endif  // __GLIBC__
 #else   // _GLIBCXX_HAVE_UNISTD_H
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   return p;
 }
@@ -706,7 +706,7 @@ fs::current_path(const path& p, error_co
   else
     ec.clear();
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -746,7 +746,7 @@ fs::equivalent(const path& p1, const pat
     {
       if (is_other(s1) && is_other(s2))
 	{
-	  ec = std::make_error_code(std::errc::not_supported);
+	  ec = std::__unsupported();
 	  return false;
 	}
       ec.clear();
@@ -762,7 +762,7 @@ fs::equivalent(const path& p1, const pat
     ec.clear();
   return false;
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   return false;
 }
@@ -793,7 +793,7 @@ namespace
       ec.clear();
       return f(st);
 #else
-      ec = std::make_error_code(std::errc::not_supported);
+      ec = std::make_error_code(std::errc::function_not_supported);
       return deflt;
 #endif
     }
@@ -817,7 +817,7 @@ fs::file_size(const path& p, error_code&
       if (s.type == file_type::directory)
 	ec = std::make_error_code(std::errc::is_a_directory);
       else
-	ec = std::make_error_code(std::errc::not_supported);
+	ec = std::__unsupported();
     }
   return -1;
 }
@@ -920,7 +920,7 @@ fs::last_write_time(const path& p __attr
   else
     ec.clear();
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
 }
 
@@ -967,7 +967,7 @@ fs::permissions(const path& p, perms prm
     err = errno;
 #else
   if (nofollow && is_symlink(st))
-    ec = std::make_error_code(std::errc::operation_not_supported);
+    ec = std::__unsupported();
   else if (posix::chmod(p.c_str(), static_cast<mode_t>(prms)))
     err = errno;
 #endif
@@ -1032,7 +1032,7 @@ fs::path fs::read_symlink(const path& p
     }
   while (true);
 #else
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   return result;
 }
@@ -1153,16 +1153,12 @@ fs::resize_file(const path& p, uintmax_t
 void
 fs::resize_file(const path& p, uintmax_t size, error_code& ec) noexcept
 {
-#ifdef _GLIBCXX_HAVE_UNISTD_H
-  if (size > static_cast<uintmax_t>(std::numeric_limits<off_t>::max()))
+  if (size > static_cast<uintmax_t>(std::numeric_limits<posix::off_t>::max()))
     ec.assign(EINVAL, std::generic_category());
   else if (posix::truncate(p.c_str(), size))
     ec.assign(errno, std::generic_category());
   else
     ec.clear();
-#else
-  ec = std::make_error_code(std::errc::not_supported);
-#endif
 }
 
 
@@ -1280,7 +1276,7 @@ fs::system_complete(const path& p, error
       || p.root_name() == base.root_name())
     return absolute(p, base);
   // else TODO
-  ec = std::make_error_code(std::errc::not_supported);
+  ec = std::__unsupported();
   return {};
 #else
   if (ec.value())
