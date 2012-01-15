$NetBSD: patch-bwbasic.h,v 1.1 2012/01/15 15:29:31 ryoon Exp $

* Suppress redefined messages.

--- bwbasic.h.orig	2009-06-04 12:50:18.000000000 +0000
+++ bwbasic.h
@@ -111,10 +111,16 @@
 ***************************************************************/
 
 #ifdef __STDC__
+#ifndef HAVE_RAISE
 #define HAVE_RAISE TRUE
+#endif
+#ifndef HAVE_STRING
 #define HAVE_STRING TRUE
+#endif
+#ifndef HAVE_STDLIB
 #define HAVE_STDLIB TRUE
 #endif
+#endif
 
 #ifdef __STDC__
 #define	HAVE_SIGNAL	TRUE
