$NetBSD: patch-frmts_jpeg2000_jpeg2000__vsil__io.cpp,v 1.1 2016/12/17 23:24:31 joerg Exp $

--- frmts/jpeg2000/jpeg2000_vsil_io.cpp.orig	2016-12-17 20:05:26.504722084 +0000
+++ frmts/jpeg2000/jpeg2000_vsil_io.cpp
@@ -206,7 +206,7 @@ static void JPEG2000_VSIL_jas_stream_ini
 			/* The buffer must be large enough to accommodate maximum
 			  putback. */
 			assert(bufsize > JAS_STREAM_MAXPUTBACK);
-			stream->bufbase_ = JAS_CAST(uchar *, buf);
+			stream->bufbase_ = JAS_CAST(unsigned char *, buf);
 			stream->bufsize_ = bufsize - JAS_STREAM_MAXPUTBACK;
 		}
 	} else {
