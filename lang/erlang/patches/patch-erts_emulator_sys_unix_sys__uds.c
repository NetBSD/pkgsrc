$NetBSD: patch-erts_emulator_sys_unix_sys__uds.c,v 1.2 2021/01/15 13:40:14 nia Exp $

Fix SunOS/C99.

--- erts/emulator/sys/unix/sys_uds.c.orig	2021-01-15 07:20:03.000000000 +0000
+++ erts/emulator/sys/unix/sys_uds.c
@@ -23,8 +23,12 @@
 #endif
 
 #if defined(__sun__) && !defined(_XOPEN_SOURCE)
+#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
+#define _XOPEN_SOURCE 500
+#else
 #define _XOPEN_SOURCE 600
 #endif
+#endif
 
 #include <limits.h>
 
