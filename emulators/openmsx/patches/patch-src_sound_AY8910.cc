$NetBSD: patch-src_sound_AY8910.cc,v 1.1 2012/08/12 01:15:00 marino Exp $

--- src/sound/AY8910.cc.orig	2007-04-14 21:25:28.000000000 +0000
+++ src/sound/AY8910.cc
@@ -19,6 +19,7 @@
 #include "MSXException.hh"
 #include "StringOp.hh"
 #include <cassert>
+#include <cstring>
 
 using std::string;
 
