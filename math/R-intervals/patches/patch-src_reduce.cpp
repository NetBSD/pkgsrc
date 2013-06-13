$NetBSD: patch-src_reduce.cpp,v 1.1 2013/06/13 14:28:38 joerg Exp $

--- src/reduce.cpp.orig	2013-06-12 19:50:00.000000000 +0000
+++ src/reduce.cpp
@@ -68,22 +68,22 @@ extern "C"
     SET_VECTOR_ELT( result, 0, allocMatrix( REALSXP, start.size(), 2 ) );
     copy( 
 	 start.begin(), start.end(),
-	 std::vector<double>::iterator ( REAL( VECTOR_ELT( result, 0 ) ) )
+	 REAL( VECTOR_ELT( result, 0 ) )
 	  );
     copy( 
 	 end.begin(), end.end(),
-	 std::vector<double>::iterator ( REAL( VECTOR_ELT( result, 0 ) ) + start.size() )
+	 REAL( VECTOR_ELT( result, 0 ) ) + start.size()
 	  );
 
     if ( full_bool ) {
       SET_VECTOR_ELT( result, 1, allocMatrix( LGLSXP, start.size(), 2 ) );
       copy( 
     	   start_c.begin(), start_c.end(),
-    	   std::vector<int>::iterator ( LOGICAL( VECTOR_ELT( result, 1 ) ) )
+    	   LOGICAL( VECTOR_ELT( result, 1 ) )
     	    );
       copy( 
     	   end_c.begin(), end_c.end(),
-    	   std::vector<int>::iterator ( LOGICAL( VECTOR_ELT( result, 1 ) ) + start.size() )
+    	   LOGICAL( VECTOR_ELT( result, 1 ) ) + start.size()
     	    );
     }
     else {
