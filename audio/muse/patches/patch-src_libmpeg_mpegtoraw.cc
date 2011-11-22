$NetBSD: patch-src_libmpeg_mpegtoraw.cc,v 1.1 2011/11/22 20:50:54 wiz Exp $

iostream.h is deprecated.

--- src/libmpeg/mpegtoraw.cc.orig	2003-12-08 12:20:37.000000000 +0000
+++ src/libmpeg/mpegtoraw.cc
@@ -419,7 +419,7 @@ bool Mpegtoraw::loadheader(void)
   return true;
 }
 
-#include <iostream.h>
+#include <iostream>
 // Convert mpeg to raw
 bool Mpegtoraw::run(int frames) {
   clearrawdata();
