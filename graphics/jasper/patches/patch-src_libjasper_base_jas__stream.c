$NetBSD: patch-src_libjasper_base_jas__stream.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3521 and CVE-2008-3522, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/base/jas_stream.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/base/jas_stream.c
@@ -212,7 +212,7 @@ jas_stream_t *jas_stream_memopen(char *b
 	if (buf) {
 		obj->buf_ = (unsigned char *) buf;
 	} else {
-		obj->buf_ = jas_malloc(obj->bufsize_ * sizeof(char));
+		obj->buf_ = jas_malloc(obj->bufsize_);
 		obj->myalloc_ = 1;
 	}
 	if (!obj->buf_) {
@@ -361,28 +361,22 @@ jas_stream_t *jas_stream_tmpfile()
 	}
 	obj->fd = -1;
 	obj->flags = 0;
-	obj->pathname[0] = '\0';
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
 
 	/* Unlink the file so that it will disappear if the program
 	terminates abnormally. */
-	/* Under UNIX, one can unlink an open file and continue to do I/O
-	on it.  Not all operating systems support this functionality, however.
-	For example, under Microsoft Windows the unlink operation will fail,
-	since the file is open. */
 	if (unlink(obj->pathname)) {
-		/* We will try unlinking the file again after it is closed. */
-		obj->flags |= JAS_STREAM_FILEOBJ_DELONCLOSE;
+		jas_stream_destroy(stream);
+		return 0;
 	}
 
 	/* Use full buffering. */
@@ -553,7 +547,7 @@ int jas_stream_printf(jas_stream_t *stre
 	int ret;
 
 	va_start(ap, fmt);
-	ret = vsprintf(buf, fmt, ap);
+	ret = vsnprintf(buf, sizeof buf, fmt, ap);
 	jas_stream_puts(stream, buf);
 	va_end(ap);
 	return ret;
@@ -992,7 +986,7 @@ static int mem_resize(jas_stream_memobj_
 	unsigned char *buf;
 
 	assert(m->buf_);
-	if (!(buf = jas_realloc(m->buf_, bufsize * sizeof(unsigned char)))) {
+	if (!(buf = jas_realloc(m->buf_, bufsize))) {
 		return -1;
 	}
 	m->buf_ = buf;
