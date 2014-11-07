$NetBSD: patch-src_file.c,v 1.1 2014/11/07 11:17:12 schmonz Exp $

Some OSes have locale_t in xlocale.h (patch from upstream).

--- src/file.c.orig	2014-09-11 15:05:33.000000000 +0000
+++ src/file.c
@@ -142,7 +142,9 @@ main(int argc, char *argv[])
 	const char *magicfile = NULL;		/* where the magic is	*/
 
 	/* makes islower etc work for other langs */
+#ifdef HAVE_SETLOCALE
 	(void)setlocale(LC_CTYPE, "");
+#endif
 
 #ifdef __EMX__
 	/* sh-like wildcard expansion! Shouldn't hurt at least ... */
