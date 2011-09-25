$NetBSD: patch-src-iassrv.c,v 1.1 2011/09/25 19:40:28 joerg Exp $

--- src/iassrv.c.orig	2011-09-25 08:59:49.000000000 +0000
+++ src/iassrv.c
@@ -33,6 +33,7 @@
 #include <ias.h>
 
 #include <string.h>
+#include <unistd.h>
 
 /**********************************************************************
  * Constants
