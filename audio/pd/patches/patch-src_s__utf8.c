$NetBSD: patch-src_s__utf8.c,v 1.2 2011/10/05 20:02:48 wiz Exp $

alloca.h is not portable.
https://sourceforge.net/tracker/?func=detail&aid=3411730&group_id=55736&atid=478072

--- src/s_utf8.c.orig	2010-08-18 03:51:01.000000000 +0000
+++ src/s_utf8.c
@@ -18,10 +18,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdarg.h>
-#ifdef WIN32
-#include <malloc.h>
-#else
+#if defined(HAVE_ALLOCA_H)
 #include <alloca.h>
+#elsif defined(HAVE_MALLOC_H)
+#include <malloc.h>
 #endif
 
 #include "s_utf8.h"
