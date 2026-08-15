$NetBSD: patch-talkd_intalkd.h,v 1.1 2026/08/15 06:46:44 wiz Exp $

Fix CVE-2026-19720.
https://codeberg.org/inetutils/inetutils/commit/81987d968ab831c08bd7e42a46f4a4823729cf1e

--- talkd/intalkd.h.orig	2026-04-29 07:53:25.000000000 +0000
+++ talkd/intalkd.h
@@ -32,6 +32,8 @@
 #include <unistd.h>
 #include <errno.h>
 
+#include "idx.h"
+
 #ifndef INADDR_NONE
 # define INADDR_NONE -1
 #endif
@@ -48,6 +50,7 @@ extern char *hostname;
 extern time_t max_idle_time;
 extern time_t max_request_ttl;
 extern char *hostname;
+extern idx_t hostname_len;
 
 #define os2sin_addr(cp) (((struct sockaddr_in *)&(cp))->sin_addr)
 
