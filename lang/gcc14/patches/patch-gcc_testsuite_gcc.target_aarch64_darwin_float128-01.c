$NetBSD: patch-gcc_testsuite_gcc.target_aarch64_darwin_float128-01.c,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- /dev/null
+++ gcc/testsuite/gcc.target/aarch64/darwin/float128-01.c
@@ -0,0 +1,48 @@
+/* { dg-do run } */
+/* we need this for _Float128.  */
+/* { dg-options "-std=gnu99 " } */
+/* { dg-additional-options "-Wfloat-conversion" } */
+
+float f1 (__float128 z1, _Float128 z2)
+{
+  float x, y;
+  x = z1; /* { dg-warning "conversion from '_Float128' to 'float'" } */
+  y = z2; /* { dg-warning "conversion from '_Float128' to 'float'" } */
+  return x + y;
+}
+
+__float128 f2 () {
+  float f = 0.q;
+  return f;
+}
+
+_Float128 f3 () {
+  float f = 0.q;
+  return f;
+}
+
+int main ()
+{
+  __float128 x1 = __builtin_huge_valq ();
+  __float128 x2 = __builtin_infq ();
+
+  _Float128 y1 = __builtin_huge_valq ();
+  _Float128 y2 = __builtin_infq ();
+
+  if (!__builtin_isinf (x1))
+    __builtin_abort();
+  if (!__builtin_isinf (x2))
+    __builtin_abort();
+
+  if (!__builtin_isinf (y1))
+    __builtin_abort();
+  if (!__builtin_isinf (y2))
+    __builtin_abort();
+
+  if (x1 != x2)
+    __builtin_abort();
+  if (y1 != y2)
+    __builtin_abort();
+
+  return 0;
+}
