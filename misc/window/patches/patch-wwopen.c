$NetBSD: patch-wwopen.c,v 1.1 2017/09/10 01:00:01 dholland Exp $

Signedness fixes: the sign bit of fmap is used in bit operations and
causes compiler warnings and build failures, so make it unsigned.

--- wwopen.c~	2003-08-07 11:17:42.000000000 +0000
+++ wwopen.c
@@ -147,7 +147,7 @@ wwopen(int type, int oflags, int nrow, i
 			w->ww_win[i][j] = m;
 
 	if (oflags & WWO_FRAME) {
-		w->ww_fmap = wwalloc(w->ww_w.t, w->ww_w.l,
+		w->ww_fmap = (unsigned char **)wwalloc(w->ww_w.t, w->ww_w.l,
 			w->ww_w.nr, w->ww_w.nc, sizeof (char));
 		if (w->ww_fmap == 0)
 			goto bad;
@@ -184,7 +184,7 @@ bad:
 		if (w->ww_win != 0)
 			wwfree(w->ww_win, w->ww_w.t);
 		if (w->ww_fmap != 0)
-			wwfree(w->ww_fmap, w->ww_w.t);
+			wwfree((char **)w->ww_fmap, w->ww_w.t);
 		if (w->ww_buf != 0)
 			wwfree((char **)w->ww_buf, w->ww_b.t);
 		if (w->ww_nvis != 0)
