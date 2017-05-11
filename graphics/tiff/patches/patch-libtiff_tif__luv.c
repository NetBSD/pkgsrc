$NetBSD: patch-libtiff_tif__luv.c,v 1.1.2.2 2017/05/11 17:47:20 bsiegert Exp $

Fix CVE-2016-10269, ref. http://bugzilla.maptools.org/show_bug.cgi?id=2604
and
https://github.com/vadz/libtiff/commit/1044b43637fa7f70fb19b93593777b78bd20da86

--- libtiff/tif_luv.c.orig	2016-09-08 13:23:57.000000000 +0000
+++ libtiff/tif_luv.c
@@ -158,6 +158,7 @@
 typedef struct logLuvState LogLuvState;
 
 struct logLuvState {
+	int			encoder_state;	/* 1 if encoder correctly initialized */
 	int                     user_datafmt;   /* user data format */
 	int                     encode_meth;    /* encoding method */
 	int                     pixel_size;     /* bytes per pixel */
@@ -1552,6 +1553,7 @@ LogLuvSetupEncode(TIFF* tif)
 		    td->td_photometric, "must be either LogLUV or LogL");
 		break;
 	}
+	sp->encoder_state = 1;
 	return (1);
 notsupported:
 	TIFFErrorExt(tif->tif_clientdata, module,
@@ -1563,19 +1565,27 @@ notsupported:
 static void
 LogLuvClose(TIFF* tif)
 {
+	LogLuvState* sp = (LogLuvState*) tif->tif_data;
 	TIFFDirectory *td = &tif->tif_dir;
 
+	assert(sp != 0);
 	/*
 	 * For consistency, we always want to write out the same
 	 * bitspersample and sampleformat for our TIFF file,
 	 * regardless of the data format being used by the application.
 	 * Since this routine is called after tags have been set but
 	 * before they have been recorded in the file, we reset them here.
+	 * Note: this is really a nasty approach. See PixarLogClose
 	 */
-	td->td_samplesperpixel =
-	    (td->td_photometric == PHOTOMETRIC_LOGL) ? 1 : 3;
-	td->td_bitspersample = 16;
-	td->td_sampleformat = SAMPLEFORMAT_INT;
+	if( sp->encoder_state )
+	{
+	    /* See PixarLogClose. Might avoid issues with tags whose size depends
+	     * on those below, but not completely sure this is enough. */
+	    td->td_samplesperpixel =
+	        (td->td_photometric == PHOTOMETRIC_LOGL) ? 1 : 3;
+	    td->td_bitspersample = 16;
+	    td->td_sampleformat = SAMPLEFORMAT_INT;
+	}
 }
 
 static void
