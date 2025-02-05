$NetBSD: patch-gcc_testsuite_gcc.target_aarch64_darwin_float128-02.c,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- /dev/null
+++ gcc/testsuite/gcc.target/aarch64/darwin/float128-02.c
@@ -0,0 +1,101 @@
+/* { dg-do run } */
+/* we need this for _Float128.  */
+/* { dg-options "-std=gnu99 " } */
+
+void test (__float128 z1, __float128 z2, __float128 z3, __float128 z4)
+{
+  __float128 w;
+
+  if (!__builtin_isinf (z1))
+    __builtin_abort();
+  if (__builtin_isnan (z1))
+    __builtin_abort();
+  if (__builtin_isfinite (z1))
+    __builtin_abort();
+  if (__builtin_isnormal (z1))
+    __builtin_abort();
+  if (__builtin_signbit (z1))
+    __builtin_abort();
+
+  if (__builtin_isinf (z2))
+    __builtin_abort();
+  if (!__builtin_isnan (z2))
+    __builtin_abort();
+  if (__builtin_isfinite (z2))
+    __builtin_abort();
+  if (__builtin_isnormal (z2))
+    __builtin_abort();
+  if (__builtin_signbit (z2))
+    __builtin_abort();
+
+  if (__builtin_isinf (z3))
+    __builtin_abort();
+  if (!__builtin_isnan (z3))
+    __builtin_abort();
+  if (__builtin_isfinite (z3))
+    __builtin_abort();
+  if (__builtin_isnormal (z3))
+    __builtin_abort();
+  if (__builtin_signbit (z3))
+    __builtin_abort();
+
+  if (__builtin_isinf (z4))
+    __builtin_abort();
+  if (__builtin_isnan (z4))
+    __builtin_abort();
+  if (!__builtin_isfinite (z4))
+    __builtin_abort();
+  if (!__builtin_isnormal (z4))
+    __builtin_abort();
+  if (__builtin_signbit (z4))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z1, -z4);
+  if (!__builtin_signbit (w))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z2, -z4);
+  if (!__builtin_signbit (w))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z3, -z4);
+  if (!__builtin_signbit (w))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z4, -z4);
+  if (!__builtin_signbit (w))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z1, -z4);
+  w = __builtin_fabsq (w);
+  if (__builtin_signbit (w))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z2, -z4);
+  w = __builtin_fabsq (w);
+  if (__builtin_signbit (w))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z3, -z4);
+  w = __builtin_fabsq (w);
+  if (__builtin_signbit (w))
+    __builtin_abort();
+
+  w = __builtin_copysignq (z4, -z4);
+  w = __builtin_fabsq (w);
+  if (__builtin_signbit (w))
+    __builtin_abort();
+
+}
+
+int main ()
+{
+  __float128 x1 = __builtin_infq ();
+  __float128 x2 = __builtin_nanq ("");
+  __float128 x3 = __builtin_nansq ("");
+  __float128 x4 = 41.1094721q;
+
+  test (x1, x2, x3, x4);
+
+  return 0;
+}
