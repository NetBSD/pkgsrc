$NetBSD: patch-gcc_testsuite_g++.target_aarch64_float128-darwin-1.C,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- /dev/null
+++ gcc/testsuite/g++.target/aarch64/float128-darwin-1.C
@@ -0,0 +1,41 @@
+/* { dg-do run { target { aarch64*-*-darwin* } } } */
+/* { dg-options "-std=c++11 -std=gnu++98" } */
+
+#include <limits>
+#include <string>
+#include <typeinfo>
+
+void foo ()
+{
+  float x1 = 1.0q;
+  double x2 = 1.0q;
+  long double x3 = 1.0q;
+
+  _Float128 w1 = 0;
+  __float128 w2 = 0;
+
+  float y1 = w1; // { dg-warning "with greater conversion rank" }
+  double y2 = w1; // { dg-warning "with greater conversion rank" }
+  long double y3 = w1; // { dg-warning "with greater conversion rank" }
+
+  float z1 = w2;
+  double z2 = w2;
+  long double z3 = w2;
+}
+
+int main ()
+{
+  // Check the correct mangling of floating-point types
+  if (typeid(float).name() != std::string("f"))
+    __builtin_abort();
+  if (typeid(double).name() != std::string("d"))
+    __builtin_abort();
+  if (typeid(long double).name() != std::string("e"))
+    __builtin_abort();
+  if (typeid(__float128).name() != std::string("g"))
+    __builtin_abort();
+  if (typeid(_Float128).name() != std::string("DF128_"))
+    __builtin_abort();
+  if (typeid(1.0q).name() != std::string("g"))
+    __builtin_abort();
+}
