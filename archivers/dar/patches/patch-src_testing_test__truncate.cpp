$NetBSD: patch-src_testing_test__truncate.cpp,v 1.1 2024/06/22 18:28:02 adam Exp $

Fix ambiguity.

--- src/testing/test_truncate.cpp.orig	2024-06-22 15:10:31.634590256 +0000
+++ src/testing/test_truncate.cpp
@@ -69,7 +69,7 @@ static void f1()
 
     fic.write(message.c_str(), message.size());
     fic.truncate(message.size()/2);
-    cout << "file size = " << deci(fic.get_position()).human() << endl;
+    cout << "file size = " << libdar::deci(fic.get_position()).human() << endl;
     fic.write(message.c_str(), message.size());
     fic.skip(message.size()/3);
     fic.truncate(message.size()/2);
@@ -82,7 +82,7 @@ static void f1()
 
     over.write(message.c_str(), message.size());
     over.truncate(message.size()/2);
-    cout << "file size = " << deci(over.get_position()).human() << endl;
+    cout << "file size = " << libdar::deci(over.get_position()).human() << endl;
     over.write(message.c_str(), message.size());
     over.skip(0);  // to flush data pending for writing
     over.write(message.c_str(), message.size());
@@ -107,13 +107,13 @@ static void f2()
     U_I lu = 0;
 
 //    mem.skip_to_eof();
-    cout << "file size = " << deci(mem.get_position()).human() << endl;
+    cout << "file size = " << libdar::deci(mem.get_position()).human() << endl;
     mem.write(message.c_str(), message.size());
-    cout << "file size = " << deci(mem.get_position()).human() << endl;
+    cout << "file size = " << libdar::deci(mem.get_position()).human() << endl;
     mem.truncate(5);
-    cout << "file size = " << deci(mem.get_position()).human() << endl;
+    cout << "file size = " << libdar::deci(mem.get_position()).human() << endl;
     mem.skip_to_eof();
-    cout << "file size = " << deci(mem.get_position()).human() << endl;
+    cout << "file size = " << libdar::deci(mem.get_position()).human() << endl;
     mem.skip(0);
     lu = mem.read(buffer, 99);
     buffer[lu] = '\0';
@@ -121,10 +121,10 @@ static void f2()
 
 static void f3()
 {
-    storage store(deci("5000000000").computer()); // 5 GByte of RAM
-    cout << "storage size = " << deci(store.size()).human() << endl;
+    storage store(libdar::deci("5000000000").computer()); // 5 GByte of RAM
+    cout << "storage size = " << libdar::deci(store.size()).human() << endl;
     store.truncate(10);
-    cout << "storage size = " << deci(store.size()).human() << endl;
+    cout << "storage size = " << libdar::deci(store.size()).human() << endl;
 }
 
 static void f4()
