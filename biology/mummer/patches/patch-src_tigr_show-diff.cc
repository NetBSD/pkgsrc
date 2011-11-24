$NetBSD: patch-src_tigr_show-diff.cc,v 1.1 2011/11/24 14:24:34 joerg Exp $

--- src/tigr/show-diff.cc.orig	2011-11-24 02:32:28.000000000 +0000
+++ src/tigr/show-diff.cc
@@ -14,6 +14,7 @@
 #include <cstdlib>
 #include <cassert>
 #include <climits>
+#include <algorithm>
 using namespace std;
 
 
