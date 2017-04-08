$NetBSD: patch-src_tlStream.cc,v 1.2 2017/04/08 13:48:52 mef Exp $

date: 2017-02-15 06:33:08 +0900;  author: joerg;  state: Exp;  commitid: BDodrFgUrNgNVXFz;
Add missing includes.

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
