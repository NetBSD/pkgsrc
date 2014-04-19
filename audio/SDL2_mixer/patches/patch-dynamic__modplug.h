$NetBSD: patch-dynamic__modplug.h,v 1.1 2014/04/19 14:52:13 joerg Exp $

--- dynamic_modplug.h.orig	2014-04-19 11:23:56.000000000 +0000
+++ dynamic_modplug.h
@@ -21,7 +21,7 @@
 
 #ifdef MODPLUG_MUSIC
 
-#include "modplug.h"
+#include "libmodplug/modplug.h"
 
 typedef struct {
     int loaded;
