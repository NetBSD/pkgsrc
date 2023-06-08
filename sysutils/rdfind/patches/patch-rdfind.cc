$NetBSD: patch-rdfind.cc,v 1.1 2023/06/08 14:35:46 joerg Exp $

--- rdfind.cc.orig	2023-06-01 12:40:33.281864990 +0000
+++ rdfind.cc
@@ -9,6 +9,7 @@
 // std
 #include <algorithm>
 #include <iostream>
+#include <limits>
 #include <string>
 #include <vector>
 
