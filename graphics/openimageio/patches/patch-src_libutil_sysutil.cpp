$NetBSD: patch-src_libutil_sysutil.cpp,v 1.5 2021/01/19 16:02:25 nia Exp $

Add support for NetBSD and other operating systems.

--- src/libutil/sysutil.cpp.orig	2021-01-08 07:41:40.000000000 +0000
+++ src/libutil/sysutil.cpp
@@ -22,7 +22,7 @@
 #    include <unistd.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #    include <sys/ioctl.h>
 #    include <sys/resource.h>
 #    include <sys/sysctl.h>
@@ -198,6 +198,13 @@ Sysutil::physical_memory()
     sysctl(mib, 2, &physical_memory, &length, NULL, 0);
     return physical_memory;
 
+#elif defined(__NetBSD__)
+    int mib[2] = { CTL_HW, HW_PHYSMEM64 };
+    uint64_t physical_memory;
+    size_t length = sizeof(physical_memory);
+    sysctl(mib, 2, &physical_memory, &length, NULL, 0);
+    return physical_memory;
+
 #else
     // No idea what platform this is
     OIIO_ASSERT(
@@ -255,12 +262,17 @@ Sysutil::this_program_path()
     size_t cb = sizeof(filename);
     int r     = 1;
     sysctl(mib, 4, filename, &cb, NULL, 0);
-#elif defined(__GNU__) || defined(__OpenBSD__) || defined(_WIN32)
-    int r = 0;
+#elif defined(__NetBSD__)
+    int mib[4];
+    mib[0]    = CTL_KERN;
+    mib[1]    = KERN_PROC_ARGS;
+    mib[2]    = -1;
+    mib[3]    = KERN_PROC_PATHNAME;
+    size_t cb = sizeof(filename);
+    int r     = 1;
+    sysctl(mib, 4, filename, &cb, NULL, 0);
 #else
-    // No idea what platform this is
-    OIIO_STATIC_ASSERT_MSG(0,
-                           "this_program_path() unimplemented on this platform");
+    int r = 0;
 #endif
 
     if (r > 0)
@@ -295,12 +307,11 @@ Sysutil::terminal_columns()
 {
     int columns = 80;  // a decent guess, if we have nothing more to go on
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) \
-    || defined(__FreeBSD_kernel__) || defined(__GNU__)
+#if !defined(_WIN32)
     struct winsize w;
     ioctl(0, TIOCGWINSZ, &w);
     columns = w.ws_col;
-#elif defined(_WIN32)
+#else
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
     if (h != INVALID_HANDLE_VALUE) {
         CONSOLE_SCREEN_BUFFER_INFO csbi = { { 0 } };
@@ -319,12 +330,11 @@ Sysutil::terminal_rows()
 {
     int rows = 24;  // a decent guess, if we have nothing more to go on
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) \
-    || defined(__FreeBSD_kernel__) || defined(__GNU__)
+#if !defined(_WIN32)
     struct winsize w;
     ioctl(0, TIOCGWINSZ, &w);
     rows = w.ws_row;
-#elif defined(_WIN32)
+#else
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
     if (h != INVALID_HANDLE_VALUE) {
         CONSOLE_SCREEN_BUFFER_INFO csbi = { { 0 } };
