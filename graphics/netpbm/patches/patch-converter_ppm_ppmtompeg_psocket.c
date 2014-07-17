$NetBSD: patch-converter_ppm_ppmtompeg_psocket.c,v 1.1 2014/07/17 15:52:26 ryoon Exp $

--- converter/ppm/ppmtompeg/psocket.c.orig	2006-08-19 03:12:28.000000000 +0000
+++ converter/ppm/ppmtompeg/psocket.c
@@ -9,7 +9,10 @@
 
 ============================================================================*/
 
+/* SCO OpenServer 5.0.7/3.2 does not typedef u_long, when _XOPEN_SOURCE is defined. */
+#if !defined(_SCO_DS)
 #define _XOPEN_SOURCE 500 /* Make sure stdio.h contains pclose() */
+#endif
 /* _ALL_SOURCE is needed on AIX to make the C library include the 
    socket services (e.g. define struct sockaddr) 
 
@@ -44,6 +47,11 @@
 #undef _XOPEN_SOURCE
 #endif
 
+/* Avoid vogus error under SCO OpenServer 5.0.7/3.2 with GCC 4.2.4. */
+#if defined(_SCO_DS)
+#define BSD 0
+#endif
+
 #include <stdarg.h>
 #include <netinet/in.h>
 #include <unistd.h>
