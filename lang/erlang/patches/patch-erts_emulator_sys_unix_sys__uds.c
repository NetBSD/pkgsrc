$NetBSD: patch-erts_emulator_sys_unix_sys__uds.c,v 1.1 2018/07/03 11:01:21 fhajny Exp $

Fix SunOS/C99.

--- erts/emulator/sys/unix/sys_uds.c.orig	2018-06-19 07:07:55.000000000 +0000
+++ erts/emulator/sys/unix/sys_uds.c
@@ -23,7 +23,11 @@
 #endif
 
 #if defined(__sun__) && !defined(_XOPEN_SOURCE)
+#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
 #define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
 #endif
 
 #include <limits.h>
