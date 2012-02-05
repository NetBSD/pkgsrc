$NetBSD: patch-src_x__list.c,v 1.3 2012/02/05 21:55:15 sbd Exp $

alloca.h is not portable.
https://sourceforge.net/tracker/?func=detail&aid=3411730&group_id=55736&atid=478072

--- src/x_list.c.orig	2010-07-21 18:37:47.000000000 +0000
+++ src/x_list.c
@@ -4,10 +4,10 @@
 
 #include "m_pd.h"
 /* #include <string.h> */
-#ifdef MSW
-#include <malloc.h>
-#else
+#if defined(HAVE_ALLOCA_H)
 #include <alloca.h>
+#elif defined(HAVE_MALLOC_H)
+#include <malloc.h>
 #endif
 
 extern t_pd *newest;
