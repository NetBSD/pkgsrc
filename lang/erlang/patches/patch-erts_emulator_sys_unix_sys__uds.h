$NetBSD: patch-erts_emulator_sys_unix_sys__uds.h,v 1.1 2018/01/29 16:54:38 jperkin Exp $

Fix SunOS/C99.

--- erts/emulator/sys/unix/sys_uds.h.orig	2017-12-11 20:10:59.000000000 +0000
+++ erts/emulator/sys/unix/sys_uds.h
@@ -26,7 +26,11 @@
 #endif
 
 #if defined(__sun__) && !defined(_XOPEN_SOURCE)
+#if (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
 #endif
 
 #include <limits.h>
