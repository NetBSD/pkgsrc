$NetBSD: patch-character__r11.cc,v 1.1 2013/05/23 15:04:44 joerg Exp $

--- character_r11.cc.orig	2013-05-23 11:21:53.000000000 +0000
+++ character_r11.cc
@@ -18,6 +18,7 @@
 
 #include <algorithm>
 #include <cstdio>
+#include <cstdlib>
 #include <vector>
 
 #include "common.h"
