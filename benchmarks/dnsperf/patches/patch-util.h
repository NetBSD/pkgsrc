$NetBSD: patch-util.h,v 1.1 2018/10/27 12:04:33 tron Exp $

Fix build with BIND 9.12.3 and newer

--- util.h.orig	2015-12-16 00:46:49.000000000 +0000
+++ util.h	2018-10-27 12:59:01.184426825 +0100
@@ -21,6 +21,8 @@
 #include <sys/time.h>
 
 #include <isc/types.h>
+#include <isc/boolean.h>
+#include <isc/int.h>
 
 #include "log.h"
 
