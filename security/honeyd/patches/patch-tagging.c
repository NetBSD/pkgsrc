$NetBSD: patch-tagging.c,v 1.1 2021/04/13 15:42:27 nia Exp $

Use libevent2 API. from FreeBSD Ports.

--- tagging.c.orig	2007-05-28 06:12:52.000000000 +0000
+++ tagging.c
@@ -73,7 +73,7 @@ tagging_init()
  */
 
 void
-encode_int(struct evbuffer *evbuf, uint32_t number)
+encode__int(struct evbuffer *evbuf, uint32_t number)
 {
 	int off = 1, nibbles = 0;
 	uint8_t data[5];
@@ -108,7 +108,7 @@ void
 tag_marshal(struct evbuffer *evbuf, uint8_t tag, void *data, uint16_t len)
 {
 	evbuffer_add(evbuf, &tag, sizeof(tag));
-	encode_int(evbuf, len);
+	encode__int(evbuf, len);
 	evbuffer_add(evbuf, data, len);
 }
 
@@ -117,10 +117,10 @@ void
 tag_marshal_int(struct evbuffer *evbuf, uint8_t tag, uint32_t integer)
 {
 	evbuffer_drain(_buf, EVBUFFER_LENGTH(_buf));
-	encode_int(_buf, integer);
+	encode__int(_buf, integer);
 
 	evbuffer_add(evbuf, &tag, sizeof(tag));
-	encode_int(evbuf, EVBUFFER_LENGTH(_buf));
+	encode__int(evbuf, EVBUFFER_LENGTH(_buf));
 	evbuffer_add_buffer(evbuf, _buf);
 }
 
@@ -135,8 +135,8 @@ tag_marshal_timeval(struct evbuffer *evb
 {
 	evbuffer_drain(_buf, EVBUFFER_LENGTH(_buf));
 
-	encode_int(_buf, tv->tv_sec);
-	encode_int(_buf, tv->tv_usec);
+	encode__int(_buf, tv->tv_sec);
+	encode__int(_buf, tv->tv_usec);
 
 	tag_marshal(evbuf, tag, EVBUFFER_DATA(_buf),
 	    EVBUFFER_LENGTH(_buf));
