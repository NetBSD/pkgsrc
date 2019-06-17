$NetBSD: patch-src_mumble_OSS.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/OSS.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/OSS.cpp
@@ -38,9 +38,10 @@
 #include <sys/ioctl.h>
 
 #include "User.h"
-#include "Global.h"
 #include "MainWindow.h"
 
+#include "Global.h"
+
 #define NBLOCKS 8
 
 class OSSEnumerator {
