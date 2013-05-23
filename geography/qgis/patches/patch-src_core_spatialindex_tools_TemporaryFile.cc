$NetBSD: patch-src_core_spatialindex_tools_TemporaryFile.cc,v 1.1 2013/05/23 15:03:27 joerg Exp $

--- src/core/spatialindex/tools/TemporaryFile.cc.orig	2013-05-23 14:06:11.000000000 +0000
+++ src/core/spatialindex/tools/TemporaryFile.cc
@@ -22,6 +22,7 @@
 #include <stdio.h>
 
 #include <Tools.h>
+#include <unistd.h>
 
 #ifdef WIN32
 #include <io.h>
