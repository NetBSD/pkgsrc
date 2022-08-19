$NetBSD: patch-core__unix_src_core__unix__stubs.c,v 1.1 2022/08/19 12:42:34 tnn Exp $

add SunOS support

--- core_unix/src/core_unix_stubs.c.orig	2022-02-15 14:18:18.000000000 +0000
+++ core_unix/src/core_unix_stubs.c
@@ -10,6 +10,9 @@
 #include <sys/socket.h>
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/socket.h>
+#elif defined(__sun)
+#include <sys/socket.h>
+#include <sys/sockio.h>
 #endif
 #include <sys/uio.h>
 #include <sys/utsname.h>
@@ -86,6 +89,9 @@ UNIX_INT63_CONST(F_GETFL)
 UNIX_INT63_CONST(F_SETFL)
 
 UNIX_INT63_CONST(O_APPEND)
+#ifndef O_ASYNC
+#define O_ASYNC 0
+#endif
 UNIX_INT63_CONST(O_ASYNC)
 #ifndef O_CLOEXEC
 #define O_CLOEXEC 0
