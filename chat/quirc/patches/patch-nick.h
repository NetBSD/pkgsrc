$NetBSD: patch-nick.h,v 1.1 2011/11/27 23:49:38 marino Exp $

--- nick.h.orig	2004-01-12 09:02:01.000000000 +0000
+++ nick.h
@@ -5,6 +5,7 @@
 #include <dmalloc.h>
 #endif
 
+#include <string.h>
 #include "support.h"
 #include "defines.h"
 
