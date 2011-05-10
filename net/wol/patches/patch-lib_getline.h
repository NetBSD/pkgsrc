$NetBSD: patch-lib_getline.h,v 1.1 2011/05/10 14:07:48 taca Exp $

Allow to use getline(3) in base system.

--- lib/getline.h.orig	2002-03-11 17:55:36.000000000 +0000
+++ lib/getline.h
@@ -18,6 +18,9 @@ Foundation, Inc., 59 Temple Place - Suit
 # define GETLINE_H_ 1
 
 # include <stdio.h>
+# include "config.h"
+
+# ifndef HAVE_GETLINE
 
 # ifndef PARAMS
 #  if defined PROTOTYPES || (defined __STDC__ && __STDC__)
@@ -35,4 +38,6 @@ int
 getdelim PARAMS ((char **_lineptr, size_t *_n, int _delimiter, FILE *_stream));
 # endif
 
+# endif
+
 #endif /* not GETLINE_H_ */
