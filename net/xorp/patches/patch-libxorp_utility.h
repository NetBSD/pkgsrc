$NetBSD: patch-libxorp_utility.h,v 1.2 2012/09/28 05:47:32 dholland Exp $

--- libxorp/utility.h.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/utility.h
@@ -31,7 +31,7 @@
  * Compile time assertion.
  */
 #ifndef static_assert
-#define static_assert(a) switch (a) case 0: case (a):
+#define static_assert(a) ((void)sizeof(int[(a) ? 1 : -1]))
 #endif /* static_assert */
 
 /*
@@ -42,7 +42,7 @@
 #ifdef UNUSED
 # undef UNUSED
 #endif /* UNUSED */
-#define UNUSED(var)	static_assert(sizeof(var) != 0)
+#define UNUSED(var)	((void)var)
 
 #ifdef __cplusplus
 #define cstring(s) (s).str().c_str()
