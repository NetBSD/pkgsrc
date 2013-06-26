$NetBSD: patch-src_testing_test__deci.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/testing/test_deci.cpp.orig	2013-06-20 19:29:44.000000000 +0000
+++ src/testing/test_deci.cpp
@@ -39,10 +39,10 @@ int main()
 
 static void f1()
 {
-    deci d1 = string("00001");
+    libdar::deci d1 = string("00001");
     infinint t = 3;
-    deci d2 = t;
-    deci d3 = infinint(125);
+    libdar::deci d2 = t;
+    libdar::deci d3 = infinint(125);
     U_I c;
 
     cout << d1.human() << endl;
