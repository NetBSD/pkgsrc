$NetBSD: patch-src_testing_testtools.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/testing/testtools.cpp.orig	2013-06-20 19:29:24.000000000 +0000
+++ src/testing/testtools.cpp
@@ -35,7 +35,7 @@ using namespace std;
 
 void display(const infinint & x)
 {
-    deci vu = x;
+    libdar::deci vu = x;
     cout << vu.human() << endl;
 }
 
