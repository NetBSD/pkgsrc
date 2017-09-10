$NetBSD: patch-wwsize.c,v 1.1 2017/09/10 01:00:01 dholland Exp $

Signedness fixes: the sign bit of fmap is used in bit operations and
causes compiler warnings and build failures, so make it unsigned.

--- wwsize.c.orig	2006-05-02 22:24:05.000000000 +0000
+++ wwsize.c
@@ -55,7 +55,7 @@ wwsize(struct ww *w, int nrow, int ncol)
 	union ww_char **buf = 0;
 	char **win = 0;
 	short *nvis = 0;
-	char **fmap = 0;
+	unsigned char **fmap = 0;
 	char m;
 
 	/*
@@ -65,7 +65,7 @@ wwsize(struct ww *w, int nrow, int ncol)
 	if (win == 0)
 		goto bad;
 	if (w->ww_fmap != 0) {
-		fmap = wwalloc(w->ww_w.t, w->ww_w.l, nrow, ncol, sizeof (char));
+		fmap = (unsigned char **)wwalloc(w->ww_w.t, w->ww_w.l, nrow, ncol, sizeof (char));
 		if (fmap == 0)
 			goto bad;
 	}
@@ -186,7 +186,7 @@ bad:
 	if (win != 0)
 		wwfree(win, w->ww_w.t);
 	if (fmap != 0)
-		wwfree(fmap, w->ww_w.t);
+		wwfree((char **)fmap, w->ww_w.t);
 	if (buf != 0)
 		wwfree((char **)buf, w->ww_b.t);
 	return -1;
