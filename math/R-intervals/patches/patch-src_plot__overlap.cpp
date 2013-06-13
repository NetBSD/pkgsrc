$NetBSD: patch-src_plot__overlap.cpp,v 1.1 2013/06/13 14:28:38 joerg Exp $

--- src/plot_overlap.cpp.orig	2013-06-12 19:47:03.000000000 +0000
+++ src/plot_overlap.cpp
@@ -79,7 +79,7 @@ extern "C"
 
     copy( 
 	 y.begin(), y.end(),
-	 std::vector<int>::iterator ( INTEGER( result ) )
+	 INTEGER( result )
 	  );
     
     UNPROTECT(1);
