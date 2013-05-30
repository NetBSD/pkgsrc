$NetBSD: patch-libxorp_utility.h,v 1.3 2013/05/30 15:37:24 joerg Exp $

--- libxorp/utility.h.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/utility.h
@@ -30,9 +30,9 @@
 /*
  * Compile time assertion.
  */
-#ifndef static_assert
-#define static_assert(a) switch (a) case 0: case (a):
-#endif /* static_assert */
+#ifndef my_static_assert
+#define my_static_assert(a) ((void)sizeof(int[(a) ? 1 : -1]))
+#endif /* my_static_assert */
 
 /*
  * A macro to avoid compilation warnings about unused functions arguments.
@@ -42,7 +42,7 @@
 #ifdef UNUSED
 # undef UNUSED
 #endif /* UNUSED */
-#define UNUSED(var)	static_assert(sizeof(var) != 0)
+#define UNUSED(var)	((void)var)
 
 #ifdef __cplusplus
 #define cstring(s) (s).str().c_str()
