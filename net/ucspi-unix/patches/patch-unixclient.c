$NetBSD: patch-unixclient.c,v 1.1 2020/11/18 14:31:43 schmonz Exp $

Include missing strlen declaration.

--- unixclient.c.orig	2015-08-12 03:05:40.000000000 +0000
+++ unixclient.c
@@ -1,6 +1,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/socket.h>
