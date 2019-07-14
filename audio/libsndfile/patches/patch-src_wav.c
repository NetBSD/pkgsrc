$NetBSD: patch-src_wav.c,v 1.1 2019/07/14 15:39:32 nia Exp $

Fix CVE-2019-3832 and CVE-2018-19758.

CVE-2019-3832 was introduced by a non-working patch for CVE-2018-19758...

Upstream commits:
https://github.com/erikd/libsndfile/commit/42132c543358cee9f7c3e9e9b15bb6c1063a608e.patch
https://github.com/erikd/libsndfile/commit/6d7ce94c020cc720a6b28719d1a7879181790008.patch

--- src/wav.c.orig	2017-04-01 07:18:02.000000000 +0000
+++ src/wav.c
@@ -1094,6 +1094,10 @@ wav_write_header (SF_PRIVATE *psf, int c
 		psf_binheader_writef (psf, "44", 0, 0) ; /* SMTPE format */
 		psf_binheader_writef (psf, "44", psf->instrument->loop_count, 0) ;
 
+		/* Make sure we don't read past the loops array end. */
+		if (psf->instrument->loop_count > ARRAY_LEN (psf->instrument->loops))
+			psf->instrument->loop_count = ARRAY_LEN (psf->instrument->loops) ;
+
 		for (tmp = 0 ; tmp < psf->instrument->loop_count ; tmp++)
 		{	int type ;
 
