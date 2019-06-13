$NetBSD: patch-Source_main.cpp,v 1.1 2019/06/13 13:04:02 nia Exp $

Include missing header.

--- Source/main.cpp.orig	2018-09-22 22:22:00.214890688 -0700
+++ Source/main.cpp	2018-09-22 22:22:22.406164183 -0700
@@ -32,6 +32,7 @@
 #include <set>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #include <zlib.h>
 
 using namespace Game;
