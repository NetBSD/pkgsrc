$NetBSD: patch-query.h,v 1.1 2011/11/27 23:49:38 marino Exp $

--- query.h.orig	2011-11-27 23:21:15.818565000 +0000
+++ query.h
@@ -5,6 +5,7 @@
 #include <dmalloc.h>
 #endif
 
+#include <string.h>
 #include "nick.h"
 #include "defines.h"
 
