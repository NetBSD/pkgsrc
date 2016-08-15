$NetBSD: patch-src_utils_lib_os_stubs.h,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
--- src/utils/lib/os_stubs.h.orig	2010-08-01 14:05:29.000000000 +0000
+++ src/utils/lib/os_stubs.h
@@ -155,8 +155,8 @@ extern OFF_T os_lseek(OS_FD fd, OFF_T po
 extern void os_ftruncate(OS_FD fd, OFF_T len, int sparse);
 extern ssize_t os_read(OS_FD fd, char *buf, size_t len);
 extern int os_getdtablesize();
-extern int64 os_getfdsize(OS_FD fd);
-extern int64 os_getfilesize(char *path);
+extern int64_t os_getfdsize(OS_FD fd);
+extern int64_t os_getfilesize(char *path);
 extern void os_set_nonblock(OS_SOCKET fd);
 extern void os_uname(char buf[]);
 extern int os_os_supported();
