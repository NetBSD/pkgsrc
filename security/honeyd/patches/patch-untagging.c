$NetBSD: patch-untagging.c,v 1.1 2021/04/13 15:42:27 nia Exp $

Use libevent2 API. from FreeBSD Ports.

--- untagging.c.orig	2007-05-28 06:12:52.000000000 +0000
+++ untagging.c
@@ -114,22 +114,29 @@ tag_peek(struct evbuffer *evbuf, uint8_t
 int
 tag_peek_length(struct evbuffer *evbuf, uint32_t *plength)
 {
-	struct evbuffer tmp;
+	struct evbuffer *tmp;
 	int res;
 
 	if (EVBUFFER_LENGTH(evbuf) < 2)
 		return (-1);
 
-	tmp = *evbuf;
-	tmp.buffer += 1;
-	tmp.off -= 1;
+	tmp = evbuffer_new ();
+	evbuffer_add_reference (tmp, evbuffer_pullup(evbuf, -1),
+				evbuffer_get_length(evbuf), NULL, NULL);
+	if (evbuffer_drain(tmp, 1) == -1) {
+		evbuffer_free (tmp);
+		return (-1);
+	}
 
-	res = decode_int_internal(plength, &tmp, 0);
-	if (res == -1)
+	res = decode_int_internal(plength, tmp, 0);
+	if (res == -1) {
+		evbuffer_free (tmp);
 		return (-1);
+	}
 
 	*plength += res + 1;
 
+	evbuffer_free (tmp);
 	return (0);
 }
 
@@ -438,7 +445,7 @@ tagging_int_test(void)
 	for (i = 0; i < TEST_MAX_INT; i++) {
 		int oldlen, newlen;
 		oldlen = EVBUFFER_LENGTH(tmp);
-		encode_int(tmp, integers[i]);
+		encode__int(tmp, integers[i]);
 		newlen = EVBUFFER_LENGTH(tmp);
 		fprintf(stderr, "\t\tencoded 0x%08x with %d bytes\n",
 		    integers[i], newlen - oldlen);
