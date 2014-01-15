$NetBSD: patch-ar_util.c,v 1.1 2014/01/15 13:50:43 joerg Exp $

--- ar/util.c.orig	2014-01-12 00:06:46.000000000 +0000
+++ ar/util.c
@@ -42,4 +42,10 @@ ELFTC_VCSID("$Id: util.c 2130 2011-11-10
 
+#if defined(__GNUC__) && __GNUC__ >= 2
+__attribute__((__format__(__printf__, 3, 0)))
+#endif
 static void	bsdar_vwarnc(struct bsdar *, int code,
 		    const char *fmt, va_list ap);
+#if defined(__GNUC__) && __GNUC__ >= 2
+__attribute__((__format__(__printf__, 3, 0)))
+#endif
 static void	bsdar_verrc(struct bsdar *bsdar, int code,
