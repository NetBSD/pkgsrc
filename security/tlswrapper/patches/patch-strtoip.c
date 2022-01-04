$NetBSD: patch-strtoip.c,v 1.1 2022/01/04 22:10:37 schmonz Exp $

Define AF_INET{,6}.

--- strtoip.c.orig	2021-12-28 05:36:39.000000000 +0000
+++ strtoip.c
@@ -1,5 +1,6 @@
 #include <string.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #include "strtoip.h"
 
 int strtoip4(unsigned char *ip, const char *x) {
