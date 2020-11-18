$NetBSD: patch-unixserver.c,v 1.1 2020/11/18 14:31:43 schmonz Exp $

Include missing strlen declaration.

--- unixserver.c.orig	2015-08-12 03:05:40.000000000 +0000
+++ unixserver.c
@@ -1,6 +1,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/socket.h>
