$NetBSD: patch-src_dvdvml.c,v 1.1 2014/11/30 02:49:28 markd Exp $

compat.h needs config.h

--- src/dvdvml.c.orig	2012-08-20 04:41:52.000000000 +0000
+++ src/dvdvml.c
@@ -626,6 +626,7 @@ char *dvdvmtext;
  * USA
  */
 
+#include "config.h"
 #include "compat.h" /* needed for bool */
 #include "dvdvm.h"
 #include "dvdvmy.h"
