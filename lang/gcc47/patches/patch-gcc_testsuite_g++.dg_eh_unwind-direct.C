$NetBSD: patch-gcc_testsuite_g++.dg_eh_unwind-direct.C,v 1.1 2014/05/10 14:14:58 richard Exp $

--- gcc/testsuite/g++.dg/eh/unwind-direct.C.orig	2014-01-18 17:52:15.019246553 +0000
+++ gcc/testsuite/g++.dg/eh/unwind-direct.C
@@ -0,0 +1,15 @@
+// PR target/59788
+// { dg-do run { target { *-*-solaris2* && { ! gld } } } }
+// { dg-options "-Wl,-Bdirect" }
+
+#include <stdexcept>
+
+int
+main(void)
+{
+  try
+    { throw std::runtime_error( "Catch me if you can!"); }
+  catch(...)
+    { return 0; }
+  return 1;
+}
