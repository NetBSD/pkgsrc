$NetBSD: patch-src_video_v9990_V9990.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/video/v9990/V9990.cc.orig	2011-11-24 02:48:14.000000000 +0000
+++ src/video/v9990/V9990.cc
@@ -10,6 +10,7 @@
 #include "SimpleDebuggable.hh"
 #include "MSXMotherBoard.hh"
 #include <cassert>
+#include <cstring>
 
 namespace openmsx {
 
