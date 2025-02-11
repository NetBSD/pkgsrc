$NetBSD: patch-os.c,v 1.1 2025/02/11 08:01:29 wiz Exp $

Add missing header for ioctl().

--- os.c.orig	2016-12-23 00:35:48.000000000 +0000
+++ os.c
@@ -25,6 +25,8 @@
 
 #include "edt.h"
 
+#include <sys/ioctl.h>
+
 #define JOURNAL_FLUSH_INTERVAL (15)
 
 static int screenmode = 0;
