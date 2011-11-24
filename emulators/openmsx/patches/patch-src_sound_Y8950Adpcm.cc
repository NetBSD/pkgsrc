$NetBSD: patch-src_sound_Y8950Adpcm.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/sound/Y8950Adpcm.cc.orig	2011-11-24 02:46:13.000000000 +0000
+++ src/sound/Y8950Adpcm.cc
@@ -5,6 +5,7 @@
 #include "Clock.hh"
 #include "Ram.hh"
 #include "MSXMotherBoard.hh"
+#include <cstring>
 
 namespace openmsx {
 
