$NetBSD: patch-plugins_check_radius.c,v 1.1 2023/01/09 00:28:41 sekiya Exp $

Support radius config.

--- plugins/check_radius.c.orig	2019-12-05 06:53:08.000000000 +0900
+++ plugins/check_radius.c	2023-01-09 08:53:32.981542458 +0900
@@ -99,7 +99,7 @@
 char *nasipaddress = NULL;
 char *castid = NULL;
 char *expect = NULL;
-char *config_file = NULL;
+char *config_file = "@SYSCONFDIR@/radiusclient-ng/radiusclient.conf";
 unsigned short port = PW_AUTH_UDP_PORT;
 int retries = 1;
 int verbose = FALSE;
