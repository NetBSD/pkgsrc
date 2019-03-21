$NetBSD: patch-src_google_protobuf_testing_zcgunzip.cc,v 1.1 2019/03/21 21:26:23 adam Exp $

Fix testing.

--- src/google/protobuf/testing/zcgunzip.cc.orig	2019-03-21 20:16:57.000000000 +0000
+++ src/google/protobuf/testing/zcgunzip.cc
@@ -42,6 +42,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #ifdef _WIN32
 #ifndef STDIN_FILENO
