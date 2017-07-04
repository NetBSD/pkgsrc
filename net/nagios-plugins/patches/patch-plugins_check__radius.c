$NetBSD: patch-plugins_check__radius.c,v 1.1 2017/07/04 19:45:18 jperkin Exp $

Support radius config.

--- plugins/check_radius.c.orig	2017-01-16 17:24:03.000000000 +0000
+++ plugins/check_radius.c
@@ -86,7 +86,7 @@ char *password = NULL;
 char *nasid = NULL;
 char *nasipaddress = NULL;
 char *expect = NULL;
-char *config_file = NULL;
+char *config_file = "@SYSCONFDIR@/radiusclient-ng/radiusclient.conf";
 unsigned short port = PW_AUTH_UDP_PORT;
 int retries = 1;
 int verbose = FALSE;
