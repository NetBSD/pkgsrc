$NetBSD: patch-perf_cairo-analyse-trace.c,v 1.2 2022/04/07 10:57:57 riastradh Exp $

Fix ctype(3) abuse.
https://gitlab.freedesktop.org/cairo/cairo/-/merge_requests/309

--- perf/cairo-analyse-trace.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ perf/cairo-analyse-trace.c
@@ -292,11 +292,11 @@ read_excludes (cairo_perf_t *perf,
 
 	/* whitespace delimits */
 	s = line;
-	while (*s != '\0' && isspace (*s))
+	while (*s != '\0' && isspace ((unsigned char)*s))
 	    s++;
 
 	t = s;
-	while (*t != '\0' && ! isspace (*t))
+	while (*t != '\0' && ! isspace ((unsigned char)*t))
 	    t++;
 
 	if (s != t) {
