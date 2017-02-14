$NetBSD: patch-src_tlStream.cc,v 1.1 2017/02/14 21:33:08 joerg Exp $

--- src/tlStream.cc.orig	2017-02-09 18:57:16.170616732 +0000
+++ src/tlStream.cc
@@ -28,6 +28,7 @@
 #include <sys/stat.h>
 #include <stdio.h>
 #include <errno.h>
+#include <unistd.h>
 #ifdef _WIN32 
 #  include <io.h>
 #endif
