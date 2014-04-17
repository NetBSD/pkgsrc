$NetBSD: patch-src_mms.c,v 1.2 2014/04/17 11:15:09 wiz Exp $

* for the case missing AI_ADDRCONFIG

--- src/mms.c.orig	2014-04-09 03:02:22.000000000 +0000
+++ src/mms.c
@@ -73,6 +73,10 @@
 #include "utf.h"
 #include "mms-common.h"
 
+#ifndef AI_ADDRCONFIG
+#define AI_ADDRCONFIG 0
+#endif
+
 /* 
  * mms specific types 
  */
