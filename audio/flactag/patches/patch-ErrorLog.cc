$NetBSD: patch-ErrorLog.cc,v 1.2 2012/11/06 18:38:34 drochner Exp $

--- ErrorLog.cc.orig	2012-10-19 21:40:21.000000000 +0000
+++ ErrorLog.cc
@@ -26,6 +26,7 @@
 ----------------------------------------------------------------------------*/
 
 #include "ErrorLog.h"
+#include <cstdio>
 
 #include <stdio.h>
 
