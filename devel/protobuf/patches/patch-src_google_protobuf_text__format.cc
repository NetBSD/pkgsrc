$NetBSD: patch-src_google_protobuf_text__format.cc,v 1.1 2019/10/08 22:11:37 otis Exp $

--- src/google/protobuf/text_format.cc.orig	2019-10-03 00:08:05.000000000 +0000
+++ src/google/protobuf/text_format.cc
@@ -35,7 +35,7 @@
 #include <google/protobuf/text_format.h>
 
 #include <float.h>
-#include <math.h>
+#include <cmath>
 #include <stdio.h>
 
 #include <algorithm>
