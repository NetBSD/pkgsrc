$NetBSD: patch-lib_assert.h,v 1.1 2022/10/29 14:44:07 he Exp $

Fix assert() macro to be usable as an expression.

--- lib/assert.h.orig	2017-08-18 00:29:14.000000000 +0000
+++ lib/assert.h
@@ -46,10 +46,10 @@
 #define INCLUDED_ASSERT_H
 
 #ifdef __STDC__
-#define assert(ex)	{if (!(ex))assertionfailed(__FILE__, __LINE__, #ex);}
+#define assert(ex)	((ex) ? (void)0 : assertionfailed(__FILE__, __LINE__, #ex))
 void assertionfailed(const char *file, int line, const char *expr);
 #else
-#define assert(ex)	{if (!(ex))assertionfailed(__FILE__, __LINE__, (char*)0);}
+#define assert(ex)	((ex) ? (void)0 : assertionfailed(__FILE__, __LINE__, (char*)0))
 #endif
 
 #endif /* INCLUDED_ASSERT_H */
