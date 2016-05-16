$NetBSD: patch-src_libjasper_jpc_jpc__qmfb.c,v 1.2 2016/05/16 14:03:40 he Exp $

Fix CVE-2014-8158.  Patch taken from
https://bugzilla.redhat.com/show_bug.cgi?id=1179298

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_qmfb.c.old	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/jpc/jpc_qmfb.c	2016-03-31 14:48:03.000000000 +0200
@@ -306,11 +306,7 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
@@ -318,15 +314,13 @@
 	register int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numcols >= 2) {
 		hstartcol = (numcols + 1 - parity) >> 1;
@@ -360,12 +354,10 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -374,11 +366,7 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
@@ -386,15 +374,13 @@
 	register int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -428,12 +414,10 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -442,11 +426,7 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize * JPC_QMFB_COLGRPSIZE];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -457,15 +437,13 @@
 	int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -517,12 +495,10 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -531,11 +507,7 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t splitbuf[QMFB_SPLITBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t splitbuf[bufsize * numcols];
-#endif
 	jpc_fix_t *buf = splitbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -546,15 +518,13 @@
 	int m;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Get a buffer. */
 	if (bufsize > QMFB_SPLITBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide in this case. */
 			abort();
 		}
 	}
-#endif
 
 	if (numrows >= 2) {
 		hstartcol = (numrows + 1 - parity) >> 1;
@@ -606,12 +576,10 @@
 		}
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the split buffer was allocated on the heap, free this memory. */
 	if (buf != splitbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -619,26 +587,20 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numcols, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
 	register int n;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numcols + 1 - parity) >> 1;
 
@@ -670,12 +632,10 @@
 		++srcptr;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -684,26 +644,20 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	register jpc_fix_t *srcptr;
 	register jpc_fix_t *dstptr;
 	register int n;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc2(bufsize, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -735,12 +689,10 @@
 		++srcptr;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -749,11 +701,7 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize * JPC_QMFB_COLGRPSIZE];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -763,15 +711,13 @@
 	register int i;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc2(bufsize, JPC_QMFB_COLGRPSIZE * sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -821,12 +767,10 @@
 		srcptr += JPC_QMFB_COLGRPSIZE;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
@@ -835,11 +779,7 @@
 {
 
 	int bufsize = JPC_CEILDIVPOW2(numrows, 1);
-#if !defined(HAVE_VLA)
 	jpc_fix_t joinbuf[QMFB_JOINBUFSIZE * JPC_QMFB_COLGRPSIZE];
-#else
-	jpc_fix_t joinbuf[bufsize * numcols];
-#endif
 	jpc_fix_t *buf = joinbuf;
 	jpc_fix_t *srcptr;
 	jpc_fix_t *dstptr;
@@ -849,15 +789,13 @@
 	register int i;
 	int hstartcol;
 
-#if !defined(HAVE_VLA)
 	/* Allocate memory for the join buffer from the heap. */
 	if (bufsize > QMFB_JOINBUFSIZE) {
-		if (!(buf = jas_malloc(bufsize * numcols * sizeof(jpc_fix_t)))) {
+		if (!(buf = jas_alloc3(bufsize, numcols, sizeof(jpc_fix_t)))) {
 			/* We have no choice but to commit suicide. */
 			abort();
 		}
 	}
-#endif
 
 	hstartcol = (numrows + 1 - parity) >> 1;
 
@@ -907,12 +845,10 @@
 		srcptr += numcols;
 	}
 
-#if !defined(HAVE_VLA)
 	/* If the join buffer was allocated on the heap, free this memory. */
 	if (buf != joinbuf) {
 		jas_free(buf);
 	}
-#endif
 
 }
 
