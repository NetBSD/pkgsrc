$NetBSD: patch-src_iperf__server__api.c,v 1.1 2015/02/02 12:25:20 he Exp $

Unused variable.

--- src/iperf_server_api.c.orig	2015-01-09 17:44:11.000000000 +0000
+++ src/iperf_server_api.c
@@ -128,7 +128,6 @@ iperf_accept(struct iperf_test *test)
 {
     int s;
     signed char rbuf = ACCESS_DENIED;
-    char cookie[COOKIE_SIZE];
     socklen_t len;
     struct sockaddr_storage addr;
 
