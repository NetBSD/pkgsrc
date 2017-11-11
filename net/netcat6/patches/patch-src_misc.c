$NetBSD: patch-src_misc.c,v 1.1 2017/11/11 17:28:39 maya Exp $

use strdup instead of being off by one with our version
of strdup

--- src/misc.c.orig	2006-01-19 22:46:23.000000000 +0000
+++ src/misc.c
@@ -119,9 +119,10 @@ void *xmalloc(size_t size)
 
 char *xstrdup(const char *str)
 {
-	register char *nstr = (char *)xmalloc(strlen(str));
-	/* we should use srtlcpy here instead of strcpy */
-	strcpy(nstr, str);
+	register char *nstr = (char *) strdup(str);
+
+	if (nstr == NULL) fatal(_("virtual memory exhausted"));
+
 	return nstr;
 }
 
