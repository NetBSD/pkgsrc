$NetBSD: patch-wwunframe.c,v 1.1 2017/09/10 01:00:01 dholland Exp $

Signedness fixes: the sign bit of fmap is used in bit operations and
causes compiler warnings and build failures, so make it unsigned.

--- wwunframe.c~	2003-08-07 11:17:46.000000000 +0000
+++ wwunframe.c
@@ -51,7 +51,7 @@ wwunframe(struct ww *w)
 	for (i = w->ww_i.t; i < w->ww_i.b; i++) {
 		int j;
 		char *win = w->ww_win[i];
-		char *fmap = w->ww_fmap ? w->ww_fmap[i] : 0;
+		unsigned char *fmap = w->ww_fmap ? w->ww_fmap[i] : 0;
 		unsigned char *smap = wwsmap[i];
 		union ww_char *ns = wwns[i];
 		int nchanged = 0;
