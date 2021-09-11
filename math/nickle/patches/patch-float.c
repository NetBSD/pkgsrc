$NetBSD: patch-float.c,v 1.1 2021/09/11 23:44:49 tnn Exp $

significand(3) is non-standard and was deprecated on mac OS aarch64.

--- float.c.orig	2012-01-30 07:25:50.000000000 +0000
+++ float.c
@@ -1124,7 +1124,11 @@ NewDoubleFloat (double d)
     double_digit    dd;
     if (d == 0.0) RETURN (Zero);
     e = ilogb (d);
+#if defined(__APPLE__)
+    m = scalb(d, (double) -ilogb(d));
+#else
     m = significand (d);
+#endif
     ms = Positive;
     if (m < 0)
     {
