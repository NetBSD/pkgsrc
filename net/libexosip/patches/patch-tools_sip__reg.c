$NetBSD: patch-tools_sip__reg.c,v 1.1 2020/03/06 13:01:47 nia Exp $

Pull in NetBSD compatibility headers for use with other headers.

--- tools/sip_reg.c.orig	2020-01-16 21:29:27.000000000 +0000
+++ tools/sip_reg.c
@@ -60,8 +60,14 @@
 
 #if !defined(WIN32) && !defined(_WIN32_WCE) && !defined(__arc__)
 #define _GNU_SOURCE
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>	/* needed for the other headers */
+#include <nbcompat/cdefs.h>	/* needed for the other headers */
+#include <nbcompat/getopt.h>
+#else
 #include <getopt.h>
 #endif
+#endif
 
 #define PROG_NAME "sipreg"
 #define PROG_VER  "1.0"
