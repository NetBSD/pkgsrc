$NetBSD: patch-src_sound_MSXMixer.cc,v 1.1 2012/08/12 01:15:00 marino Exp $

--- src/sound/MSXMixer.cc.orig	2007-04-14 21:25:28.000000000 +0000
+++ src/sound/MSXMixer.cc
@@ -14,6 +14,7 @@
 #include "AviRecorder.hh"
 #include <algorithm>
 #include <cassert>
+#include <cstring>
 
 using std::remove;
 using std::set;
