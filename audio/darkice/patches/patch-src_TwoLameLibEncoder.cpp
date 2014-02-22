$NetBSD: patch-src_TwoLameLibEncoder.cpp,v 1.1 2014/02/22 14:51:03 wiedi Exp $

Fix broken amd64 build.
--- src/TwoLameLibEncoder.cpp.orig	2013-07-15 05:50:42.000000000 +0000
+++ src/TwoLameLibEncoder.cpp
@@ -116,7 +116,7 @@ TwoLameLibEncoder :: open ( void )
     if ( !twolame_opts  ) {
         throw Exception( __FILE__, __LINE__,
                          "TwoLAME lib init error",
-                         (long int) twolame_opts);
+                         /* (long int) twolame_opts */ /* why? */ 0);
     }
 
     if ( 0 > twolame_set_num_channels( twolame_opts, getInChannel()) ) {
