$NetBSD: patch-serversession.cc,v 1.1 2011/11/25 22:14:17 joerg Exp $

--- serversession.cc.orig	2011-11-25 19:21:11.000000000 +0000
+++ serversession.cc
@@ -17,6 +17,7 @@
 #include <sys/ioctl.h>
 #include <sys/resource.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <syslog.h>
 #include <unistd.h>
 #include <fcntl.h>
