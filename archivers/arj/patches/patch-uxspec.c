$NetBSD: patch-uxspec.c,v 1.1 2015/04/12 15:45:00 tnn Exp $

Fix build on systems without lchown.

--- uxspec.c.orig	2004-04-17 11:39:42.000000000 +0000
+++ uxspec.c
@@ -13,6 +13,11 @@
  #include <unistd.h>
 #endif
 
+#include "c_defs.h"
+#ifndef HAVE_LCHOWN
+#define lchown chown
+#endif
+
 DEBUGHDR(__FILE__)                      /* Debug information block */
 
 /* UXSPECIAL block types */
