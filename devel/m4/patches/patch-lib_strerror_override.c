$NetBSD: patch-lib_strerror_override.c,v 1.2 2021/06/28 18:30:57 wiz Exp $

Fix build on QNX.

--- lib/strerror-override.c.orig	2016-12-31 13:54:42.000000000 +0000
+++ lib/strerror-override.c
@@ -29,6 +29,8 @@
 # endif
 #endif
 
+/* strerror_override.h might define it to NULL. */
+#ifndef strerror_override
 /* If ERRNUM maps to an errno value defined by gnulib, return a string
    describing the error.  Otherwise return NULL.  */
 const char *
@@ -300,3 +302,4 @@ strerror_override (int errnum)
       return NULL;
     }
 }
+#endif
