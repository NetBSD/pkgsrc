$NetBSD: patch-src_video_VDP.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/video/VDP.cc.orig	2011-11-24 02:47:33.000000000 +0000
+++ src/video/VDP.cc
@@ -33,6 +33,7 @@ TODO:
 #include "MSXCliComm.hh"
 #include <sstream>
 #include <cassert>
+#include <cstring>
 
 namespace openmsx {
 
