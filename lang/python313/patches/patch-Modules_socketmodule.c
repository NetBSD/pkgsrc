$NetBSD: patch-Modules_socketmodule.c,v 1.1 2024/10/09 19:53:20 adam Exp $

SunOS needs _XOPEN_SOURCE for sendmsg bits that are now required.

--- Modules/socketmodule.c.orig	2023-12-07 20:45:44.000000000 +0000
+++ Modules/socketmodule.c
@@ -89,6 +89,9 @@ Local naming conventions:
 #  define Py_BUILD_CORE_MODULE 1
 #endif
 
+#ifdef __sun
+#define _XOPEN_SOURCE	600
+#endif
 #ifdef __APPLE__
 // Issue #35569: Expose RFC 3542 socket options.
 #define __APPLE_USE_RFC_3542 1
