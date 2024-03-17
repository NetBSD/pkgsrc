$NetBSD: patch-src_pan-view_pan-util.cc,v 1.1 2024/03/17 13:55:11 wiz Exp $

Restrict Linux-specific header to Linux.

--- src/pan-view/pan-util.cc.orig	2024-03-17 13:53:55.384404282 +0000
+++ src/pan-view/pan-util.cc
@@ -21,7 +21,9 @@
 
 #include "pan-util.h"
 
+#ifdef __linux__
 #include <features.h>
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 
