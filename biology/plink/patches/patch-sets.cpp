$NetBSD: patch-sets.cpp,v 1.1 2012/11/16 00:32:07 joerg Exp $

--- sets.cpp.orig	2012-11-15 12:39:15.000000000 +0000
+++ sets.cpp
@@ -768,11 +768,11 @@ vector_t Set::profileTestScore()
       //////////////////////////////////////////////
       // Reset original missing status
 
-      vector<Individual*>::iterator i = PP->sample.begin();
-      while ( i != PP->sample.end() )
+      vector<Individual*>::iterator i2 = PP->sample.begin();
+      while ( i2 != PP->sample.end() )
 	{
-	  (*i)->missing = (*i)->flag;
-	  ++i;
+	  (*i2)->missing = (*i2)->flag;
+	  ++i2;
 	}
 
       ////////////////////////////////////////////////
