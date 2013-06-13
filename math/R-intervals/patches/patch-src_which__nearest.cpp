$NetBSD: patch-src_which__nearest.cpp,v 1.1 2013/06/13 14:28:38 joerg Exp $

--- src/which_nearest.cpp.orig	2013-06-12 19:51:17.000000000 +0000
+++ src/which_nearest.cpp
@@ -185,7 +185,7 @@ extern "C"
 
     copy( 
 	 delta.begin(), delta.end(),
-	 std::vector<double>::iterator ( REAL( VECTOR_ELT( result, 0 ) ) )
+	 REAL( VECTOR_ELT( result, 0 ) )
 	  );
 		    
     for( i = 0; i < tn; i++ ) {      
@@ -195,7 +195,7 @@ extern "C"
 		      );
       copy( 
 	   which[i].begin(), which[i].end(), 
-	   std::vector<int>::iterator ( INTEGER( VECTOR_ELT( VECTOR_ELT( result, 1 ), i ) ) )
+	   INTEGER( VECTOR_ELT( VECTOR_ELT( result, 1 ), i ) )
 	    );
       SET_VECTOR_ELT( 
 		     VECTOR_ELT( result, 2 ), i, 
@@ -203,7 +203,7 @@ extern "C"
 		      );
       copy( 
 	   indices[i].begin(), indices[i].end(), 
-	   std::vector<int>::iterator ( INTEGER( VECTOR_ELT( VECTOR_ELT( result, 2 ), i ) ) )
+	   INTEGER( VECTOR_ELT( VECTOR_ELT( result, 2 ), i ) )
 	    );
     }
 
