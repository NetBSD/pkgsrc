$NetBSD: patch-compat_fts.c,v 1.1 2015/01/05 13:21:17 jperkin Exp $

Provide compat O_CLOEXEC define.

--- compat_fts.c.orig	2014-12-13 14:06:34.000000000 +0000
+++ compat_fts.c
@@ -66,6 +66,9 @@ static int	 fts_safe_changedir(FTS *, FT
 #ifndef	O_DIRECTORY
 #define	O_DIRECTORY	0
 #endif
+#ifndef	O_CLOEXEC
+#define	O_CLOEXEC	0
+#endif
 
 #define	CLR(opt)	(sp->fts_options &= ~(opt))
 #define	ISSET(opt)	(sp->fts_options & (opt))
