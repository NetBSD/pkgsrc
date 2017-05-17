$NetBSD: patch-src_flac.c,v 1.2 2017/05/17 21:58:05 he Exp $

Fix for CVE-2017-8365, ref.
https://github.com/erikd/libsndfile/commit/fd0484aba8e51d16af1e3a880f9b8b857b385eb3
Fix for CVE-2017-8362, ref.
https://github.com/erikd/libsndfile/commit/ef1dbb2df1c0e741486646de40bd638a9c4cd808

--- src/flac.c.orig	2017-04-02 08:13:30.000000000 +0000
+++ src/flac.c
@@ -169,6 +169,14 @@ flac_buffer_copy (SF_PRIVATE *psf)
 	const int32_t* const *buffer = pflac->wbuffer ;
 	unsigned i = 0, j, offset, channels, len ;
 
+	if (psf->sf.channels != (int) frame->header.channels)
+	{	psf_log_printf (psf, "Error: FLAC frame changed from %d to %d channels\n"
+					    "Nothing to do but to error out.\n" ,
+					    psf->sf.channels, frame->header.channels) ;
+		psf->error = SFE_FLAC_CHANNEL_COUNT_CHANGED ;
+		return 0 ;
+		} ;
+
 	/*
 	**	frame->header.blocksize is variable and we're using a constant blocksize
 	**	of FLAC__MAX_BLOCK_SIZE.
@@ -202,7 +210,6 @@ flac_buffer_copy (SF_PRIVATE *psf)
 		return 0 ;
 		} ;
 
-
 	len = SF_MIN (pflac->len, frame->header.blocksize) ;
 
 	if (pflac->remain % channels != 0)
@@ -435,6 +442,19 @@ sf_flac_meta_callback (const FLAC__Strea
 
 	switch (metadata->type)
 	{	case FLAC__METADATA_TYPE_STREAMINFO :
+			if (psf->sf.channels > 0 && psf->sf.channels != (int) metadata->data.stream_info.channels)
+			{	psf_log_printf (psf, "Error: FLAC stream changed from %d to %d channels\n"
+						    "Nothing to do but to error out.\n" ,
+						    psf->sf.channels, metadata->data.stream_info.channels) ;
+				psf->error = SFE_FLAC_CHANNEL_COUNT_CHANGED ;
+				return ;
+				} ;
+
+			if (psf->sf.channels > 0 && psf->sf.samplerate != (int) metadata->data.stream_info.sample_rate)
+			{	psf_log_printf (psf, "Warning: FLAC stream changed sample rates from %d to %d.\n"
+						    "Carrying on as if nothing happened.",
+						    psf->sf.samplerate, metadata->data.stream_info.sample_rate) ;
+				} ;
 			psf->sf.channels = metadata->data.stream_info.channels ;
 			psf->sf.samplerate = metadata->data.stream_info.sample_rate ;
 			psf->sf.frames = metadata->data.stream_info.total_samples ;
