$NetBSD: patch-tagging.h,v 1.2 2021/04/13 15:42:27 nia Exp $

Use libevent2 API. from FreeBSD Ports.

--- tagging.h.orig	2007-05-28 06:12:52.000000000 +0000
+++ tagging.h
@@ -86,7 +86,7 @@ void addr_marshal(struct evbuffer *, str
 void tag_marshal(struct evbuffer *evbuf, uint8_t tag, void *data,
     uint16_t len);
 
-void encode_int(struct evbuffer *evbuf, uint32_t number);
+void encode__int(struct evbuffer *evbuf, uint32_t number);
 
 void tag_marshal_int(struct evbuffer *evbuf, uint8_t tag, uint32_t integer);
 
