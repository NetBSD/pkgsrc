$NetBSD: patch-idhelp.cpp,v 1.1 2012/11/16 00:32:07 joerg Exp $

--- idhelp.cpp.orig	2012-11-15 12:44:01.000000000 +0000
+++ idhelp.cpp
@@ -772,12 +772,12 @@ void IDHelper::idHelp()
       for (int j = 0 ; j < jointField.size(); j++ )
 	{
 	  set<IDField*> & jf = jointField[j];
-	  set<IDField*>::iterator j = jf.begin();
+	  set<IDField*>::iterator j2 = jf.begin();
 	  PP->printLOG(" { ");
-	  while ( j != jf.end() )
+	  while ( j2 != jf.end() )
 	    {
-	      PP->printLOG( (*j)->name + " " );
-	      ++j;
+	      PP->printLOG( (*j2)->name + " " );
+	      ++j2;
 	    }
 	  PP->printLOG(" }");
 	}
