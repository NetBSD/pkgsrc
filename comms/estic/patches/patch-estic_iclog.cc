$NetBSD: patch-estic_iclog.cc,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- estic/iclog.cc.orig	2012-11-15 10:44:05.000000000 +0000
+++ estic/iclog.cc
@@ -31,6 +31,7 @@
 #include "iccli.h"
 #include "iclog.h"
 
+#undef DS
 
 
 /*****************************************************************************/
