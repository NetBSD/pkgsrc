$NetBSD: patch-wwlabel.c,v 1.1 2017/09/10 01:00:01 dholland Exp $

Signedness fixes: the sign bit of fmap is used in bit operations and
causes compiler warnings and build failures, so make it unsigned.

--- wwlabel.c~	2009-04-14 08:50:06.000000000 +0000
+++ wwlabel.c
@@ -58,7 +58,7 @@ wwlabel(struct ww *w, struct ww *f, int 
 	char *win;
 	union ww_char *buf;
 	union ww_char *ns;
-	char *fmap;
+	unsigned char *fmap;
 	unsigned char *smap;
 	char touched;
 	const char *p;
