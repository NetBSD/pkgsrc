$NetBSD: patch-vsnprintf.c,v 1.1.1.1 2011/11/08 16:10:51 taca Exp $

Avoid ugly warning.

--- vsnprintf.c.orig	2011-01-18 17:56:10.000000000 +0000
+++ vsnprintf.c
@@ -209,7 +209,9 @@ typedef	struct __sFILE {
 #define	__sfeof(p)	(((p)->_flags & __SEOF) != 0)
 #define	__sferror(p)	(((p)->_flags & __SERR) != 0)
 #define	__sclearerr(p)	((void)((p)->_flags &= ~(__SERR|__SEOF)))
+#ifndef __sfileno
 #define	__sfileno(p)	((p)->_file)
+#endif
 
 #undef feof
 #undef ferror
