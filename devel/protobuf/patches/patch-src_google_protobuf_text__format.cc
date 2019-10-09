$NetBSD: patch-src_google_protobuf_text__format.cc,v 1.2 2019/10/09 08:46:22 otis Exp $

Fix build on NetBSD 8.1 with gcc 5.5.0.

Also, pull request with upstream has been opened at:
https://github.com/protocolbuffers/protobuf/pull/6747

--- src/google/protobuf/text_format.cc.orig	2019-10-03 00:08:05.000000000 +0000
+++ src/google/protobuf/text_format.cc
@@ -35,7 +35,7 @@
 #include <google/protobuf/text_format.h>
 
 #include <float.h>
-#include <math.h>
+#include <cmath>
 #include <stdio.h>
 
 #include <algorithm>
