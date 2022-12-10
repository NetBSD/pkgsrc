$NetBSD: patch-libstdc++-v3_src_filesystem_ops-common.h,v 1.1 2022/12/10 10:44:59 js Exp $

From https://gcc.gnu.org/pipermail/gcc-patches/2021-October/580752.html with
adjustments

--- ./libstdc++-v3/src/filesystem/ops-common.h.orig	2021-07-28 06:55:09.340315989 +0000
+++ ./libstdc++-v3/src/filesystem/ops-common.h
@@ -56,6 +56,31 @@
 namespace std _GLIBCXX_VISIBILITY(default)
 {
 _GLIBCXX_BEGIN_NAMESPACE_VERSION
+
+// Get an error code indicating unsupported functionality.
+//
+// This should be used when a function is unable to behave as specified
+// due to an incomplete or partial implementation, e.g.
+// filesystem::equivalent(a, b) if is_other(a) && is_other(b) is true.
+//
+// Use errc::function_not_supported for functions that are entirely
+// unimplemented, e.g. create_symlink on Windows.
+//
+// Use errc::invalid_argument for requests to perform operations outside
+// the spec, e.g. trying to copy a directory using filesystem::copy_file.
+inline error_code
+__unsupported() noexcept
+{
+#if defined ENOTSUP
+  return std::make_error_code(std::errc::not_supported);
+#elif defined EOPNOTSUPP
+  // This is supposed to be for socket operations
+  return std::make_error_code(std::errc::operation_not_supported);
+#else
+  return std::make_error_code(std::errc::invalid_argument);
+#endif
+}
+
 namespace filesystem
 {
 namespace __gnu_posix
@@ -115,6 +140,7 @@ namespace __gnu_posix
     return -1;
   }
 
+  using off_t = _off64_t;
   inline int truncate(const wchar_t* path, _off64_t length)
   {
     const int fd = ::_wopen(path, _O_BINARY|_O_RDWR);
@@ -151,6 +177,7 @@ namespace __gnu_posix
   using ::utime;
 # endif
   using ::rename;
+  using ::off_t;
 # ifdef _GLIBCXX_HAVE_TRUNCATE
   using ::truncate;
 # else
@@ -170,15 +197,16 @@ namespace __gnu_posix
 # endif
   using char_type = char;
 #else // ! _GLIBCXX_FILESYSTEM_IS_WINDOWS && ! _GLIBCXX_HAVE_UNISTD_H
-  inline int open(const char*, int, ...) { errno = ENOTSUP; return -1; }
-  inline int close(int) { errno = ENOTSUP; return -1; }
+  inline int open(const char*, int, ...) { errno = ENOSYS; return -1; }
+  inline int close(int) { errno = ENOSYS; return -1; }
   using mode_t = int;
-  inline int chmod(const char*, mode_t) { errno = ENOTSUP; return -1; }
-  inline int mkdir(const char*, mode_t) { errno = ENOTSUP; return -1; }
-  inline char* getcwd(char*, size_t) { errno = ENOTSUP; return nullptr; }
-  inline int chdir(const char*) { errno = ENOTSUP; return -1; }
-  inline int rename(const char*, const char*) { errno = ENOTSUP; return -1; }
-  inline int truncate(const char*, long) { errno = ENOTSUP; return -1; }
+  inline int chmod(const char*, mode_t) { errno = ENOSYS; return -1; }
+  inline int mkdir(const char*, mode_t) { errno = ENOSYS; return -1; }
+  inline char* getcwd(char*, size_t) { errno = ENOSYS; return nullptr; }
+  inline int chdir(const char*) { errno = ENOSYS; return -1; }
+  inline int rename(const char*, const char*) { errno = ENOSYS; return -1; }
+  using off_t = long;
+  inline int truncate(const char*, off_t) { errno = ENOSYS; return -1; }
   using char_type = char;
 #endif // _GLIBCXX_FILESYSTEM_IS_WINDOWS
 } // namespace __gnu_posix
@@ -361,7 +389,7 @@ _GLIBCXX_BEGIN_NAMESPACE_FILESYSTEM
     // 2712. copy_file() has a number of unspecified error conditions
     if (!is_regular_file(f))
       {
-	ec = std::make_error_code(std::errc::not_supported);
+	ec = std::make_error_code(std::errc::invalid_argument);
 	return false;
       }
 
@@ -369,7 +397,7 @@ _GLIBCXX_BEGIN_NAMESPACE_FILESYSTEM
       {
 	if (!is_regular_file(t))
 	  {
-	    ec = std::make_error_code(std::errc::not_supported);
+	    ec = std::make_error_code(std::errc::invalid_argument);
 	    return false;
 	  }
 
@@ -400,7 +428,7 @@ _GLIBCXX_BEGIN_NAMESPACE_FILESYSTEM
 	  }
 	else if (!is_regular_file(t))
 	  {
-	    ec = std::make_error_code(std::errc::not_supported);
+	    ec = std::make_error_code(std::errc::invalid_argument);
 	    return false;
 	  }
       }
@@ -559,7 +587,7 @@ _GLIBCXX_BEGIN_NAMESPACE_FILESYSTEM
     else
       ec.assign((int)GetLastError(), std::system_category());
 #else
-    ec = std::make_error_code(std::errc::not_supported);
+    ec = std::make_error_code(std::errc::function_not_supported);
 #endif
   }
 #pragma GCC diagnostic pop
