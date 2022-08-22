$NetBSD: patch-src_lyxfind.cpp,v 1.1 2022/08/22 08:12:47 markd Exp $

gcc 12

--- src/lyxfind.cpp.orig	2020-12-29 16:50:45.000000000 +0000
+++ src/lyxfind.cpp
@@ -13,6 +13,7 @@
  */
 
 #include <config.h>
+#include <iterator>
 
 #include "lyxfind.h"
 
