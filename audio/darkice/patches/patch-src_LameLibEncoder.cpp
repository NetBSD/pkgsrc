$NetBSD: patch-src_LameLibEncoder.cpp,v 1.1 2014/02/22 14:51:03 wiedi Exp $

Fix broken amd64 build
--- src/LameLibEncoder.cpp.orig	2013-07-15 05:50:42.000000000 +0000
+++ src/LameLibEncoder.cpp
@@ -81,10 +81,10 @@ LameLibEncoder :: open ( void )
     // ugly lame returns -1 in a pointer on allocation errors
     // this is cast to (long int) so that the pointer can be handled
     // on 64 bit systems as well
-    if ( !lameGlobalFlags || ((long int)lameGlobalFlags) == -1 ) {
+    if ( !lameGlobalFlags || lameGlobalFlags == (lame_global_flags *)-1 ) {
         throw Exception( __FILE__, __LINE__,
                          "lame lib init error",
-                         (long int) lameGlobalFlags);
+                         (long int)(intptr_t) lameGlobalFlags);
     }
 
     if ( 0 > lame_set_num_channels( lameGlobalFlags, getInChannel()) ) {
