$NetBSD: patch-src_definitions.h,v 1.1 2020/12/01 11:21:16 nia Exp $

Avoid redefining bool.

--- src/definitions.h.orig	2020-07-18 06:57:36.000000000 +0000
+++ src/definitions.h
@@ -43,12 +43,10 @@
 
 /*==== Misc definitions ====*/
 /* Define a bool type if not already defined (C++ and C99 do)*/
-#if !(defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 19990601L))
-/*@-incondefs@*/
-typedef enum {false, true} bool;
-/*@+incondefs@*/
-#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 19990601L
+#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
 #include <stdbool.h>
+#else
+typedef enum {false, true} bool;
 #endif
 
 /*==== Configuration definitions ====*/
