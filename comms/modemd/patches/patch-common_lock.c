$NetBSD: patch-common_lock.c,v 1.1 2017/02/17 17:00:03 joerg Exp $

--- common/lock.c.orig	2017-02-17 16:09:19.801857592 +0000
+++ common/lock.c
@@ -47,6 +47,7 @@ static char copyright[] =
 #include <stdio.h>
 #include <fcntl.h>
 #include <syslog.h>
+#include <sys/stat.h>
 #include "mcap.h"
 #include "ttio.h"
 
