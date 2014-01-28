$NetBSD: patch-jmorecfg.h,v 1.3 2014/01/28 21:19:00 wiz Exp $

Fix problem with booleans by reverting to the old definition.

--- jmorecfg.h.orig	2013-09-17 07:20:20.000000000 +0000
+++ jmorecfg.h
@@ -303,19 +303,14 @@ typedef void noreturn_t;
  * Defining HAVE_BOOLEAN before including jpeglib.h should make it work.
  */
 
-#ifndef HAVE_BOOLEAN
-#if defined FALSE || defined TRUE || defined QGLOBAL_H
-/* Qt3 defines FALSE and TRUE as "const" variables in qglobal.h */
-typedef int boolean;
 #ifndef FALSE			/* in case these macros already exist */
 #define FALSE	0		/* values of boolean */
 #endif
 #ifndef TRUE
 #define TRUE	1
 #endif
-#else
-typedef enum { FALSE = 0, TRUE = 1 } boolean;
-#endif
+#ifndef HAVE_BOOLEAN
+typedef int boolean;
 #endif
 
 
