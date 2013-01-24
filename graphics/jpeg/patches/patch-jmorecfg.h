$NetBSD: patch-jmorecfg.h,v 1.1 2013/01/24 22:10:43 adam Exp $

Avoid problems when FALSE and TRUE are defined as preprocessor macros.

--- jmorecfg.h.orig	2012-08-08 14:23:20.000000000 +0000
+++ jmorecfg.h
@@ -252,15 +252,14 @@ typedef void noreturn_t;
  * Defining HAVE_BOOLEAN before including jpeglib.h should make it work.
  */
 
-#ifdef HAVE_BOOLEAN
 #ifndef FALSE			/* in case these macros already exist */
 #define FALSE	0		/* values of boolean */
 #endif
 #ifndef TRUE
 #define TRUE	1
 #endif
-#else
-typedef enum { FALSE = 0, TRUE = 1 } boolean;
+#ifndef HAVE_BOOLEAN
+typedef int boolean;
 #endif
 
 
