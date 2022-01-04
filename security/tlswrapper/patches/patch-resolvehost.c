$NetBSD: patch-resolvehost.c,v 1.1 2022/01/04 22:10:37 schmonz Exp $

Define struct sockaddr_in{,6}.

--- resolvehost.c.orig	2021-12-28 05:36:39.000000000 +0000
+++ resolvehost.c
@@ -11,6 +11,7 @@ Public domain.
 #include <sys/wait.h>
 #include <signal.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include "e.h"
 #include "blocking.h"
 #include "log.h"
