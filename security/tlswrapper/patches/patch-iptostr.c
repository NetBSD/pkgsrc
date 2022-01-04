$NetBSD: patch-iptostr.c,v 1.1 2022/01/04 22:10:37 schmonz Exp $

Define AF_INET{,6}.

--- iptostr.c.orig	2021-12-28 05:36:39.000000000 +0000
+++ iptostr.c
@@ -6,6 +6,7 @@ Public domain.
 
 #include <arpa/inet.h>
 #include <string.h>
+#include <sys/socket.h>
 #include "iptostr.h"
 
 /* convert IPv4 address */
