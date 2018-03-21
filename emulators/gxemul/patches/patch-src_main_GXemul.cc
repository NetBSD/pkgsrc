$NetBSD: patch-src_main_GXemul.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/main/GXemul.cc.orig	2014-08-17 08:45:14.000000000 +0000
+++ src/main/GXemul.cc
@@ -515,7 +515,7 @@ string GXemul::Version()
 #else
 	    << "(unknown version)"
 #endif
-	    << "      "COPYRIGHT_MSG"\n"SECONDARY_MSG;
+	    << "      " COPYRIGHT_MSG "\n" SECONDARY_MSG;
 
 	return ss.str();
 }
@@ -1164,4 +1164,3 @@ UNITTESTS(GXemul)
 
 
 #endif
-
