$NetBSD: patch-src_flac.c,v 1.1 2017/05/17 21:51:46 he Exp $

Fix for CVE-2017-8365, ref.
https://github.com/erikd/libsndfile/commit/fd0484aba8e51d16af1e3a880f9b8b857b385eb3

--- src/flac.c.orig	2017-04-02 08:13:30.000000000 +0000
+++ src/flac.c
@@ -435,6 +435,19 @@ sf_flac_meta_callback (const FLAC__Strea
 
 	switch (metadata->type)
 	{	case FLAC__METADATA_TYPE_STREAMINFO :
+			if (psf->sf.channels > 0 && psf->sf.channels != (int) metadata->data.stream_info.channels)
+			{	psf_log_printf (psf, "Error: FLAC stream changed from %d to %d channels\n"
+						    "Nothing to be but to error out.\n" ,
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
