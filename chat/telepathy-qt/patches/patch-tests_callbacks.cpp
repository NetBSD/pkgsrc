$NetBSD: patch-tests_callbacks.cpp,v 1.1 2018/05/15 10:12:28 jperkin Exp $

Avoid ++ on bool.

--- tests/callbacks.cpp.orig	2015-05-24 19:33:18.000000000 +0000
+++ tests/callbacks.cpp
@@ -20,41 +20,41 @@ struct MyCallbacks
         reset();
     }
 
-    void testVV() { mVVCalled++; }
+    void testVV() { mVVCalled = true; }
     void testVI1(int a1)
     {
         QCOMPARE(a1, 1);
-        mVI1Called++;
+        mVI1Called = true;
     }
     void testVI2(int a1, int a2)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2);
-        mVI2Called++;
+        mVI2Called = true;
     }
     void testVI3(int a1, int a2, int a3)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3);
-        mVI3Called++;
+        mVI3Called = true;
     }
     void testVI4(int a1, int a2, int a3, int a4)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4);
-        mVI4Called++;
+        mVI4Called = true;
     }
     void testVI5(int a1, int a2, int a3, int a4, int a5)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4); QCOMPARE(a5, 5);
-        mVI5Called++;
+        mVI5Called = true;
     }
     void testVI6(int a1, int a2, int a3, int a4, int a5, int a6)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4); QCOMPARE(a5, 5); QCOMPARE(a6, 6);
-        mVI6Called++;
+        mVI6Called = true;
     }
     void testVI7(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4); QCOMPARE(a5, 5); QCOMPARE(a6, 6); QCOMPARE(a7, 7);
-        mVI7Called++;
+        mVI7Called = true;
     }
 
     void reset()
@@ -103,41 +103,41 @@ namespace
     bool mVI6Called;
     bool mVI7Called;
 
-    void testVV() { mVVCalled++; }
+    void testVV() { mVVCalled = true; }
     void testVI1(int a1)
     {
         QCOMPARE(a1, 1);
-        mVI1Called++;
+        mVI1Called = true;
     }
     void testVI2(int a1, int a2)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2);
-        mVI2Called++;
+        mVI2Called = true;
     }
     void testVI3(int a1, int a2, int a3)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3);
-        mVI3Called++;
+        mVI3Called = true;
     }
     void testVI4(int a1, int a2, int a3, int a4)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4);
-        mVI4Called++;
+        mVI4Called = true;
     }
     void testVI5(int a1, int a2, int a3, int a4, int a5)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4); QCOMPARE(a5, 5);
-        mVI5Called++;
+        mVI5Called = true;
     }
     void testVI6(int a1, int a2, int a3, int a4, int a5, int a6)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4); QCOMPARE(a5, 5); QCOMPARE(a6, 6);
-        mVI6Called++;
+        mVI6Called = true;
     }
     void testVI7(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
     {
         QCOMPARE(a1, 1); QCOMPARE(a2, 2); QCOMPARE(a3, 3); QCOMPARE(a4, 4); QCOMPARE(a5, 5); QCOMPARE(a6, 6); QCOMPARE(a7, 7);
-        mVI7Called++;
+        mVI7Called = true;
     }
 
     void reset()
