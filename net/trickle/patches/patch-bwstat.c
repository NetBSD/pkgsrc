$NetBSD: patch-bwstat.c,v 1.1 2026/09/12 15:04:23 wiz Exp $

bwstat_getdelay() does its pool/npts pool-sharing arithmetic in
unsigned ints, which underflow to huge values; make ncli, pool and
xent signed and stop at xent <= 0.  Also initialise bs->pts in
bwstat_alloc().  Part of a patch posted to netbsd-users on 2025-02-20
that fixes the Memory fault crash on NetBSD.

--- bwstat.c.orig
+++ bwstat.c
@@ -69,6 +69,7 @@
 	if ((bs = calloc(1, sizeof(*bs))) == NULL)
 		return (NULL);
 
+	bs->pts = 1;
 	TAILQ_INSERT_TAIL(&statq, bs, next);
 
 	return (bs);
@@ -143,7 +144,8 @@
 struct timeval *
 bwstat_getdelay(struct bwstat *bs, size_t *len, uint lim, short which)
 {
-	uint rate = 0, ncli = 0, npts = 0, pool = 0, ent, xent;
+	uint rate = 0, npts = 0, ent;
+	int ncli = 0, pool = 0, xent;
 	double delay;
 	static struct timeval tv;
 	struct bwstathead poolq;
@@ -201,7 +203,7 @@
 		if (ncli > 0) {
 			xent = pool / npts;
 
-			if (xent == 0)
+			if (xent <= 0)
 				break;
 
 			TAILQ_FOREACH(xbs, &poolq, qnext)
