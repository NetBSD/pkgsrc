$NetBSD: patch-card.cpp,v 1.1 2011/11/22 18:11:14 joerg Exp $

--- card.cpp.orig	2011-11-22 17:05:24.000000000 +0000
+++ card.cpp
@@ -1,3 +1,4 @@
+#include <cstdlib>
 #include <cstdio>
 #include <math.h>
 #ifdef SHAPE
