$NetBSD: patch-backend_genesys_low.cpp,v 1.1 2020/08/16 22:42:09 gutteridge Exp $

Fix big-endian builds. Patch from Gentoo:
https://gitweb.gentoo.org/repo/gentoo.git/commit/?id=49491819885af7f659dafe3a116ada80fbcfe1d7

--- backend/genesys/low.cpp.orig	2020-05-17 11:54:18.000000000 +0000
+++ backend/genesys/low.cpp
@@ -539,7 +539,7 @@ Image read_unshuffled_image_from_scanner
     }
 
 #ifdef WORDS_BIGENDIAN
-    if (depth == 16) {
+    if (session.params.depth == 16) {
         dev->pipeline.push_node<ImagePipelineNodeSwap16BitEndian>();
     }
 #endif
