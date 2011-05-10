$NetBSD: patch-lib_getline.c,v 1.1 2011/05/10 14:07:48 taca Exp $

Allow to use getline(3) in base system.

--- lib/getline.c.orig	2003-08-23 15:59:52.000000000 +0000
+++ lib/getline.c
@@ -34,6 +34,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <sys/types.h>
 
 #if defined __GNU_LIBRARY__ && HAVE_GETDELIM
+#ifndef HAVE_GETLINE
 
 ssize_t
 getline (char **lineptr, size_t *n, FILE *stream)
@@ -41,6 +42,7 @@ getline (char **lineptr, size_t *n, FILE
   return getdelim (lineptr, n, '\n', stream);
 }
 
+#endif
 #else /* ! have getdelim */
 
 # include "getstr.h"
