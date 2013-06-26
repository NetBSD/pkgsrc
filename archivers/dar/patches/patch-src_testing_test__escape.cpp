$NetBSD: patch-src_testing_test__escape.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/testing/test_escape.cpp.orig	2013-06-20 19:30:16.000000000 +0000
+++ src/testing/test_escape.cpp
@@ -121,5 +121,5 @@ void f2()
 	cout << "OK" << endl;
     else
 	cout << "NOK" << endl;
-    cout << deci(tested.get_position()).human() << endl;
+    cout << libdar::deci(tested.get_position()).human() << endl;
 }
