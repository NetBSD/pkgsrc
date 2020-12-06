$NetBSD: patch-tools_sip__reg.c,v 1.2 2020/12/06 23:40:21 schwarz Exp $

Pull in NetBSD compatibility headers for use with other headers.

--- tools/sip_reg.c.orig	2020-08-19 14:51:31.000000000 +0200
+++ tools/sip_reg.c	2020-12-07 00:02:10.000000000 +0100
@@ -48,8 +48,14 @@
 
 #if !defined(WIN32)
 #define _GNU_SOURCE
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>	/* needed for the other headers */
+#include <nbcompat/cdefs.h>	/* needed for the other headers */
+#include <nbcompat/getopt.h>
+#else
 #include <getopt.h>
 #endif
+#endif
 
 #define PROG_NAME "sip_reg"
 #define SYSLOG_FACILITY LOG_DAEMON
