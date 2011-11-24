$NetBSD: patch-src_video_v9990_V9990VRAM.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/video/v9990/V9990VRAM.cc.orig	2011-11-24 02:48:37.000000000 +0000
+++ src/video/v9990/V9990VRAM.cc
@@ -2,6 +2,7 @@
 
 #include "V9990.hh"
 #include "V9990VRAM.hh"
+#include <cstring>
 
 namespace openmsx {
 
