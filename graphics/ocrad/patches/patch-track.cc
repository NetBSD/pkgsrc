$NetBSD: patch-track.cc,v 1.1 2013/05/23 15:04:44 joerg Exp $

--- track.cc.orig	2013-05-23 11:21:18.000000000 +0000
+++ track.cc
@@ -18,6 +18,7 @@
 
 #include <algorithm>
 #include <cstdio>
+#include <cstdlib>
 #include <vector>
 
 #include "common.h"
