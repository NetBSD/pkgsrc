$NetBSD: patch-src_os.cpp,v 1.1 2019/02/17 12:33:40 maya Exp $

--- src/os.cpp.orig	2019-02-17 10:28:53.000000000 +0000
+++ src/os.cpp
@@ -50,11 +50,11 @@ typedef SSIZE_T ssize_t;
 
 #endif
 
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
 #include <link.h>
 #endif
 
-#if defined(ZIG_OS_FREEBSD)
+#if defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
 #include <sys/sysctl.h>
 #endif
 
@@ -78,7 +78,7 @@ static clock_serv_t cclock;
 #if defined(__APPLE__) && !defined(environ)
 #include <crt_externs.h>
 #define environ (*_NSGetEnviron())
-#elif defined(ZIG_OS_FREEBSD)
+#elif defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
 extern char **environ;
 #endif
 
@@ -1458,6 +1458,15 @@ Error os_self_exe_path(Buf *out_path) {
     }
     buf_resize(out_path, cb - 1);
     return ErrorNone;
+#elif defined(ZIG_OS_NETBSD)
+    buf_resize(out_path, PATH_MAX);
+    int mib[4] = { CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME };
+    size_t cb = PATH_MAX;
+    if (sysctl(mib, 4, buf_ptr(out_path), &cb, nullptr, 0) != 0) {
+        return ErrorUnexpected;
+    }
+    buf_resize(out_path, cb - 1);
+    return ErrorNone;
 #endif
     return ErrorFileNotFound;
 }
@@ -1776,7 +1785,7 @@ Error os_get_app_data_dir(Buf *out_path,
 }
 
 
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
 static int self_exe_shared_libs_callback(struct dl_phdr_info *info, size_t size, void *data) {
     ZigList<Buf *> *libs = reinterpret_cast< ZigList<Buf *> *>(data);
     if (info->dlpi_name[0] == '/') {
@@ -1787,7 +1796,7 @@ static int self_exe_shared_libs_callback
 #endif
 
 Error os_self_exe_shared_libs(ZigList<Buf *> &paths) {
-#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD)
+#if defined(ZIG_OS_LINUX) || defined(ZIG_OS_FREEBSD) || defined(ZIG_OS_NETBSD)
     paths.resize(0);
     dl_iterate_phdr(self_exe_shared_libs_callback, &paths);
     return ErrorNone;
