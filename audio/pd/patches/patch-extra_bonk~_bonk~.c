$NetBSD: patch-extra_bonk~_bonk~.c,v 1.3 2012/02/05 21:55:15 sbd Exp $

alloca.h is not portable.
https://sourceforge.net/tracker/?func=detail&aid=3411730&group_id=55736&atid=478072

--- extra/bonk~/bonk~.c.orig	2010-08-19 01:37:00.000000000 +0000
+++ extra/bonk~/bonk~.c
@@ -82,10 +82,10 @@ void *bonk_class;
 static t_class *bonk_class;
 #endif
 
-#ifdef _WIN32
-#include <malloc.h>
-#elif ! defined(_MSC_VER)
+#if defined(HAVE_ALLOCA_H)
 #include <alloca.h>
+#elif defined(HAVE_MALLOC_H)
+#include <malloc.h>
 #endif
 
 /* ------------------------ bonk~ ----------------------------- */
