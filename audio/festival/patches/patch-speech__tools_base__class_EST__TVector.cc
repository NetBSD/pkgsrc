$NetBSD: patch-speech__tools_base__class_EST__TVector.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/base_class/EST_TVector.cc.orig	2012-04-27 13:01:33.000000000 +0000
+++ speech_tools/base_class/EST_TVector.cc
@@ -258,7 +258,7 @@ int EST_TVector<T>::operator == (const E
 	return 0;
 
     for(int i=0; i<num_columns() ; i++)
-      if (fast_a_v(i) != v.fast_a_v(i))
+      if (!(fast_a_v(i) == v.fast_a_v(i)))
 	return 0;
     return 1;
 }
