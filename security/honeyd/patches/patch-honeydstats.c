$NetBSD: patch-honeydstats.c,v 1.1 2021/04/13 15:42:27 nia Exp $

Use libevent2 API. from FreeBSD Ports.

--- honeydstats.c.orig	2007-05-28 06:12:52.000000000 +0000
+++ honeydstats.c
@@ -330,30 +330,43 @@ signature_process(struct evbuffer *evbuf
 static int
 signature_length(struct evbuffer *evbuf)
 {
-	struct evbuffer tmp;
+	struct evbuffer *tmp;
 	uint32_t length, tlen;
 
-	tmp = *evbuf;
-
+	tmp = evbuffer_new();
+	tmp = evbuffer_add_reference(tmp, evbuffer_pullup(evbuf, -1),
+				     evbuffer_get_length(evbuf), NULL, NULL);
 	/* name */
-	if (tag_peek_length(&tmp, &tlen) == -1 || EVBUFFER_LENGTH(&tmp) < tlen)
+	if (tag_peek_length(tmp, &tlen) == -1 || EVBUFFER_LENGTH(tmp) < tlen) {
+		evbuffer_free(tmp);
 		return (-1);
+	}
+
+	if (evbuffer_drain(tmp, tlen) == -1) {
+		evbuffer_free(tmp);
+		return (-1);
+	}
 		
 	length = tlen;
-	tmp.buffer += tlen;
-	tmp.off -= tlen;
 
 	/* signature */
-	if (tag_peek_length(&tmp, &tlen) == -1 || EVBUFFER_LENGTH(&tmp) < tlen)
+	if (tag_peek_length(tmp, &tlen) == -1 || EVBUFFER_LENGTH(tmp) < tlen) {
+		evbuffer_free(tmp);
 		return (-1);
+	}
 		
+	if (evbuffer_drain(tmp, tlen) == -1) {
+		evbuffer_free(tmp);
+		return (-1);
+	}
+
 	length += tlen;
-	tmp.buffer += tlen;
-	tmp.off -= tlen;
 
 	/* data */
-	if (tag_peek_length(&tmp, &tlen) == -1 || EVBUFFER_LENGTH(&tmp) < tlen)
+	if (tag_peek_length(tmp, &tlen) == -1 || EVBUFFER_LENGTH(tmp) < tlen) {
+		evbuffer_free(tmp);
 		return (-1);
+	}
 		
 	length += tlen;
 
