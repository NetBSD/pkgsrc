$NetBSD: patch-src_sndfile.c,v 1.1 2017/05/17 21:51:46 he Exp $

Fix for CVE-2017-8365, ref.
https://github.com/erikd/libsndfile/commit/fd0484aba8e51d16af1e3a880f9b8b857b385eb3

--- src/sndfile.c.orig	2017-04-02 06:33:16.000000000 +0000
+++ src/sndfile.c
@@ -245,6 +245,7 @@ ErrorStruct SndfileErrors [] =
 	{	SFE_FLAC_INIT_DECODER	, "Error : problem with initialization of the flac decoder." },
 	{	SFE_FLAC_LOST_SYNC		, "Error : flac decoder lost sync." },
 	{	SFE_FLAC_BAD_SAMPLE_RATE, "Error : flac does not support this sample rate." },
+	{	SFE_FLAC_CHANNEL_COUNT_CHANGED, "Error : flac channel changed mid stream." },
 	{	SFE_FLAC_UNKOWN_ERROR	, "Error : unknown error in flac decoder." },
 
 	{	SFE_WVE_NOT_WVE			, "Error : not a WVE file." },
