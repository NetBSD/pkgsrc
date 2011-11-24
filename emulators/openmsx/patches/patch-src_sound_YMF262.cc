$NetBSD: patch-src_sound_YMF262.cc,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/sound/YMF262.cc.orig	2011-11-24 02:46:36.000000000 +0000
+++ src/sound/YMF262.cc
@@ -43,6 +43,7 @@
 #include "SimpleDebuggable.hh"
 #include "MSXMotherBoard.hh"
 #include <cmath>
+#include <cstring>
 
 namespace openmsx {
 
