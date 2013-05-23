$NetBSD: patch-profile.cc,v 1.1 2013/05/23 15:04:44 joerg Exp $

--- profile.cc.orig	2013-05-23 11:21:35.000000000 +0000
+++ profile.cc
@@ -18,6 +18,7 @@
 
 #include <algorithm>
 #include <cstdio>
+#include <cstdlib>
 #include <vector>
 
 #include "common.h"
