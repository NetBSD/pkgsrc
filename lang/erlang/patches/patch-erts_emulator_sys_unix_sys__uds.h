$NetBSD: patch-erts_emulator_sys_unix_sys__uds.h,v 1.2 2018/03/16 11:45:29 fhajny Exp $

Fix SunOS/C99.

--- erts/emulator/sys/unix/sys_uds.h.orig	2018-03-13 20:11:05.000000000 +0000
+++ erts/emulator/sys/unix/sys_uds.h
@@ -26,7 +26,11 @@
 #endif
 
 #if defined(__sun__) && !defined(_XOPEN_SOURCE)
+#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
 #define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
 #endif
 
 #include <limits.h>
