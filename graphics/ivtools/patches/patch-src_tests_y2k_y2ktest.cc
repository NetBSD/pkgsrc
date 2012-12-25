$NetBSD: patch-src_tests_y2k_y2ktest.cc,v 1.1 2012/12/25 21:09:08 joerg Exp $

--- src/tests/y2k/y2ktest.cc.orig	2012-12-25 18:08:34.000000000 +0000
+++ src/tests/y2k/y2ktest.cc
@@ -25,7 +25,7 @@
 using std::cin;
 using std::cout;
 
-main() {
+int main() {
   Date date(1, "Jan", 1999);
 
   cout << "Current date initialized to ";
