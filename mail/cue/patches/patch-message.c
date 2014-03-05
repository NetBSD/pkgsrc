$NetBSD: patch-message.c,v 1.1 2014/03/05 12:11:46 obache Exp $

Fixes a crash on a mail with many headers.
2014-02-24 Sent upstream.

--- message.c.orig	2014-02-03 14:27:20.000000000 +0000
+++ message.c
@@ -663,7 +663,7 @@ message_multipart_next(struct filedb *fd
 		fdb->flags |= FDB_INLINE;
 		i = fdb->hdrs + nfdb->hdrs;
 		if (i > fdb->hdr_size) {
-			p = realloc(fdb->hdr, i);
+			p = realloc(fdb->hdr, sizeof(*p) * i);
 			if (!p)
 				abort();
 			fdb->hdr = p;
@@ -739,12 +739,17 @@ message_header(struct filedb *fdb)
 	fdb->hdr = malloc(sizeof(struct header) * fdb->hdr_size);
 	n = message_header_readbuf(fdb, fdb->hdr, fdb->hdr_size);
 	if (n > fdb->hdr_size) {
+		int n2;
+
 		p = realloc(fdb->hdr, sizeof(struct header) * n);
 		if (!p)
 			abort();
 		fdb->hdr = p;
-		n = message_header_readbuf(fdb, fdb->hdr + fdb->hdr_size,
+		n2 = message_header_readbuf(fdb, fdb->hdr + fdb->hdr_size,
 		    n - fdb->hdr_size);
+		if (n != n2 + fdb->hdr_size)
+		    abort();
+		fdb->hdr_size = n;
 	}
 	fdb->hdrs = n;
 	if (fdb->flags & FDB_MULTIPART) {
