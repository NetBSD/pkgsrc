$NetBSD: patch-mozilla_gfx_graphite2_src_Bidi.cpp,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/gfx/graphite2/src/Bidi.cpp.orig	2016-04-07 21:33:13.000000000 +0000
+++ mozilla/gfx/graphite2/src/Bidi.cpp
@@ -31,6 +31,11 @@ of the License or (at your option) any l
 
 using namespace graphite2;
 
+#ifdef __sun
+#undef CS
+#undef ES
+#endif
+
 enum DirCode {  // Hungarian: dirc
         Unk        = -1,
         N          =  0,   // other neutrals (default) - ON
