$NetBSD: patch-src_mms.c,v 1.1 2013/07/13 09:28:25 obache Exp $

* for the case missing AI_ADDRCONFIG

--- src/mms.c.orig	2011-01-17 10:40:09.000000000 +0000
+++ src/mms.c
@@ -70,6 +70,10 @@
 #include "uri.h"
 #include "mms-common.h"
 
+#ifndef AI_ADDRCONFIG
+#define AI_ADDRCONFIG 0
+#endif
+
 /* 
  * mms specific types 
  */
