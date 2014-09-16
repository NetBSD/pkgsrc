$NetBSD: patch-src_gpgrt-int.h,v 1.1 2014/09/16 23:17:49 tron Exp $

Fix build under Mac OS X.

Patch taken from GIT commit <e1882ee8c541020ec590bf096508ca5b6d2ab944>.

--- src/gpgrt-int.h.orig	2014-09-11 10:39:04.000000000 +0100
+++ src/gpgrt-int.h	2014-09-17 00:14:02.000000000 +0100
@@ -105,9 +105,9 @@
 
 int _gpgrt_fflush (gpgrt_stream_t stream);
 int _gpgrt_fseek (gpgrt_stream_t stream, long int offset, int whence);
-int _gpgrt_fseeko (gpgrt_stream_t stream, off_t offset, int whence);
+int _gpgrt_fseeko (gpgrt_stream_t stream, gpgrt_off_t offset, int whence);
 long int _gpgrt_ftell (gpgrt_stream_t stream);
-off_t _gpgrt_ftello (gpgrt_stream_t stream);
+gpgrt_off_t _gpgrt_ftello (gpgrt_stream_t stream);
 void _gpgrt_rewind (gpgrt_stream_t stream);
 
 int _gpgrt_fgetc (gpgrt_stream_t stream);
