$NetBSD: patch-src_libjasper_base_jas__stream.c,v 1.2 2016/12/16 09:44:44 he Exp $

Use mkstemp instead of tmpnam-based temp file creation.

--- src/libjasper/base/jas_stream.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/base/jas_stream.c
@@ -517,11 +517,10 @@ jas_stream_t *jas_stream_tmpfile()
 	stream->obj_ = obj;
 
 	/* Choose a file name. */
-	tmpnam(obj->pathname);
+	snprintf(obj->pathname, L_tmpnam, "%stmp.XXXXXXXXXX", P_tmpdir);
 
 	/* Open the underlying file. */
-	if ((obj->fd = open(obj->pathname, O_CREAT | O_EXCL | O_RDWR | O_TRUNC | O_BINARY,
-	  JAS_STREAM_PERMS)) < 0) {
+	if ((obj->fd = mkstemp(obj->pathname)) < 0) {
 		jas_stream_destroy(stream);
 		return 0;
 	}
@@ -533,8 +532,8 @@ jas_stream_t *jas_stream_tmpfile()
 	For example, under Microsoft Windows the unlink operation will fail,
 	since the file is open. */
 	if (unlink(obj->pathname)) {
-		/* We will try unlinking the file again after it is closed. */
-		obj->flags |= JAS_STREAM_FILEOBJ_DELONCLOSE;
+		jas_stream_destroy(stream);
+		return 0;
 	}
 
 	/* Use full buffering. */
