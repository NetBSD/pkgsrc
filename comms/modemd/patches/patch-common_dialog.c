$NetBSD: patch-common_dialog.c,v 1.1 2013/09/10 18:24:10 joerg Exp $

--- common/dialog.c.orig	2013-09-10 11:53:40.000000000 +0000
+++ common/dialog.c
@@ -47,6 +47,7 @@ static char copyright[] =
 #include <stdio.h>
 #include <fcntl.h>
 #include <syslog.h>
+#include <sys/ioctl.h>
 #include "mcap.h"
 #include "ttio.h"
 
