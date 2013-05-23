$NetBSD: patch-feats__test0.cc,v 1.1 2013/05/23 15:04:44 joerg Exp $

--- feats_test0.cc.orig	2013-05-23 11:22:05.000000000 +0000
+++ feats_test0.cc
@@ -18,6 +18,7 @@
 
 #include <algorithm>
 #include <cstdio>
+#include <cstdlib>
 #include <vector>
 
 #include "common.h"
