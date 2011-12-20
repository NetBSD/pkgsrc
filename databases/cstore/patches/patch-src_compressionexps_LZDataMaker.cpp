$NetBSD: patch-src_compressionexps_LZDataMaker.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/compressionexps/LZDataMaker.cpp.orig	2006-10-18 06:04:07.000000000 +0000
+++ src/compressionexps/LZDataMaker.cpp
@@ -31,7 +31,7 @@
  /**
  */
 #include "LZDataMaker.h"
-#include <fstream.h>
+#include <fstream>
 
 LZDataMaker::LZDataMaker() {
 }
