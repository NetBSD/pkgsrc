$NetBSD: patch-lib-src_libnyquist_nyquist_nyqsrc_sndread.c,v 1.1 2015/04/21 01:33:39 rodent Exp $

Fixes "error: invalid operands to binary" build failure.

--- lib-src/libnyquist/nyquist/nyqsrc/sndread.c.orig	2015-03-02 01:07:21.000000000 +0000
+++ lib-src/libnyquist/nyquist/nyqsrc/sndread.c
@@ -166,7 +166,7 @@ LVAL snd_make_read(
 #ifdef XL_BIG_ENDIAN
         long format = SF_ENDIAN_LITTLE;
 #endif
-        susp->sf_info.format |= format;
+        susp->sf_info.format |= (int) format;
     }
 
     susp->sndfile = sf_open((const char *) filename, SFM_READ, 
