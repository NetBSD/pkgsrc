$NetBSD: patch-src_testing_test__terminateur.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/testing/test_terminateur.cpp.orig	2013-06-20 19:28:01.000000000 +0000
+++ src/testing/test_terminateur.cpp
@@ -83,7 +83,7 @@ static void f1()
     for(S_I i=2;i<30;i++)
         grand *= i;
 
-    deci conv = grand;
+    libdar::deci conv = grand;
     cout << conv.human() << endl;
     term.set_catalogue_start(grand);
     term.dump(toto);
