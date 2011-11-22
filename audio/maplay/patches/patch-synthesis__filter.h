$NetBSD: patch-synthesis__filter.h,v 1.1 2011/11/22 20:57:35 wiz Exp $

--- synthesis_filter.h.orig	1994-06-23 12:14:40.000000000 +0000
+++ synthesis_filter.h
@@ -21,7 +21,7 @@
 #ifndef SYNTHESIS_FILTER_H
 #define SYNTHESIS_FILTER_H
 
-#include <iostream.h>
+#include <iostream>
 #include "all.h"
 #include "obuffer.h"
 
