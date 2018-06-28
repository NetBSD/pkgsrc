$NetBSD: patch-src_util_fixed__point.h,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/util/fixed_point.h.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/util/fixed_point.h
@@ -79,7 +79,7 @@ public:
     operator unsigned int() const { return v>>precision; }
 
     operator float() const { return ldexpf(v,-precision); }
-    operator double() const { return ldexp(v,-precision); }
+    operator double() const { return std::ldexp(v,-precision); }
 private:
     T v;
 };
