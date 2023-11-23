$NetBSD: patch-seq_aseqnet_aseqnet.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- seq/aseqnet/aseqnet.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ seq/aseqnet/aseqnet.c
@@ -334,7 +334,7 @@ static void get_net_addr(struct addrinfo
 /*
  * signal handler
  */
-static void sigterm_exit(int)
+static void sigterm_exit(int sig ATTRIBUTE_UNUSED)
 {
 	close_files();
 	exit(1);
