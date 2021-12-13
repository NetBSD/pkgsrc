$NetBSD: patch-udpconnect.c,v 1.2 2021/12/13 21:59:09 schmonz Exp $

Provide definition of structs timeval and sockaddr_in.

--- udpconnect.c.orig	2016-03-29 19:44:38.000000000 +0000
+++ udpconnect.c
@@ -1,6 +1,8 @@
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/param.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include "sig.h"
 #include "exit.h"
 #include "sgetopt.h"
