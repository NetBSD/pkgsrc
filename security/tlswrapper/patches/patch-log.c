$NetBSD: patch-log.c,v 1.1 2022/01/04 22:10:37 schmonz Exp $

Define AF_INET{,6} and struct sockaddr_in{,6}.

--- log.c.orig	2021-12-28 05:36:39.000000000 +0000
+++ log.c
@@ -22,6 +22,8 @@ name .......... optional
 #include <stdlib.h>
 #include <time.h>
 #include <unistd.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include "e.h"
 #include "randommod.h"
 #include "log.h"
