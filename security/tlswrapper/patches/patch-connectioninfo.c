$NetBSD: patch-connectioninfo.c,v 1.1 2022/01/04 22:10:37 schmonz Exp $

Define struct sockaddr_in{,6}.

--- connectioninfo.c.orig	2021-12-28 05:36:39.000000000 +0000
+++ connectioninfo.c
@@ -10,6 +10,7 @@ Public domain.
 #include <arpa/inet.h>
 #include <stdlib.h>
 #include <string.h>
+#include <netinet/in.h>
 #include "strtoip.h"
 #include "strtoport.h"
 #include "porttostr.h"
