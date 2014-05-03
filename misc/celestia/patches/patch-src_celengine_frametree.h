$NetBSD: patch-src_celengine_frametree.h,v 1.1 2014/05/03 13:05:13 alnsn Exp $

Add include file for NULL.

--- src/celengine/frametree.h.orig	2011-06-05 16:11:09.000000000 +0000
+++ src/celengine/frametree.h
@@ -13,6 +13,7 @@
 #ifndef _CELENGINE_FRAMETREE_H_
 #define _CELENGINE_FRAMETREE_H_
 
+#include <cstddef>
 #include <vector>
 
 class Star;
