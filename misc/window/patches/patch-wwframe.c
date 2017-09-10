$NetBSD: patch-wwframe.c,v 1.1 2017/09/10 01:00:01 dholland Exp $

Signedness fixes: the sign bit of fmap is used in bit operations and
causes compiler warnings and build failures, so make it unsigned.

--- wwframe.c~	2003-08-07 11:17:39.000000000 +0000
+++ wwframe.c
@@ -194,9 +194,9 @@ wwframe(struct ww *w, struct ww *wframe)
 }
 
 void
-wwframec(struct ww *f, int r, int c, char code)
+wwframec(struct ww *f, int r, int c, unsigned char code)
 {
-	char oldcode;
+	unsigned char oldcode;
 	unsigned char *smap;
 
 	if (r < f->ww_i.t || r >= f->ww_i.b || c < f->ww_i.l || c >= f->ww_i.r)
@@ -216,7 +216,7 @@ wwframec(struct ww *f, int r, int c, cha
 	}
 
 	if (f->ww_fmap != 0) {
-		char *fmap;
+		unsigned char *fmap;
 
 		fmap = &f->ww_fmap[r][c];
 		oldcode = *fmap;
