$NetBSD: patch-src_common.h,v 1.1 2017/05/17 21:51:46 he Exp $

Fix for CVE-2017-8365, ref.
https://github.com/erikd/libsndfile/commit/fd0484aba8e51d16af1e3a880f9b8b857b385eb3

--- src/common.h.orig	2017-04-01 09:40:45.000000000 +0000
+++ src/common.h
@@ -725,6 +725,7 @@ enum
 	SFE_FLAC_INIT_DECODER,
 	SFE_FLAC_LOST_SYNC,
 	SFE_FLAC_BAD_SAMPLE_RATE,
+	SFE_FLAC_CHANNEL_COUNT_CHANGED,
 	SFE_FLAC_UNKOWN_ERROR,
 
 	SFE_WVE_NOT_WVE,
