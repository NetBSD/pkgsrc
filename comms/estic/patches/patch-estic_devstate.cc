$NetBSD: patch-estic_devstate.cc,v 1.1 2012/11/16 00:37:45 joerg Exp $

--- estic/devstate.cc.orig	1997-01-31 03:57:14.000000000 +0000
+++ estic/devstate.cc
@@ -38,6 +38,7 @@
 #include "iccom.h"
 #include "iclog.h"
 
+#undef DS
 
 
 /*****************************************************************************/
