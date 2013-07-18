$NetBSD: patch-control.c,v 1.2 2013/07/18 12:06:39 joerg Exp $

Remove static from inline; each inlined copy might have its own buffer and
this is not want you want if you define it static. In this case it does not
matter, since it is only 4K and we don't return it, so don't try to play
around with saving stack space for no good reason.

--- control.c.orig	2013-06-17 10:17:24.000000000 +0000
+++ control.c
@@ -75,7 +75,7 @@ struct buffer *new_outgoing (struct tunn
     return tmp;
 }
 
-inline void recycle_outgoing (struct buffer *buf, struct sockaddr_in peer)
+void recycle_outgoing (struct buffer *buf, struct sockaddr_in peer)
 {
     /* 
      * This should only be used for ZLB's!
@@ -1139,7 +1139,7 @@ int control_finish (struct tunnel *t, st
     return 0;
 }
 
-inline int check_control (const struct buffer *buf, struct tunnel *t,
+static inline int check_control (const struct buffer *buf, struct tunnel *t,
                           struct call *c)
 {
     /*
@@ -1275,7 +1275,7 @@ inline int check_control (const struct b
     return 0;
 }
 
-inline int check_payload (struct buffer *buf, struct tunnel *t,
+static inline int check_payload (struct buffer *buf, struct tunnel *t,
                           struct call *c)
 {
     /*
@@ -1381,7 +1381,7 @@ inline int check_payload (struct buffer 
 #endif
     return 0;
 }
-inline int expand_payload (struct buffer *buf, struct tunnel *t,
+static inline int expand_payload (struct buffer *buf, struct tunnel *t,
                            struct call *c)
 {
     /*
@@ -1561,7 +1561,7 @@ void send_zlb (void *data)
     toss (buf);
 }
 
-inline int write_packet (struct buffer *buf, struct tunnel *t, struct call *c,
+static inline int write_packet (struct buffer *buf, struct tunnel *t, struct call *c,
                          int convert)
 {
     /*
@@ -1571,7 +1571,7 @@ inline int write_packet (struct buffer *
     int x;
     unsigned char e;
     int err;
-    static unsigned char wbuf[MAX_RECV_SIZE];
+    unsigned char wbuf[MAX_RECV_SIZE];
     int pos = 0;
 
     if (c->fd < 0)
@@ -1739,7 +1739,7 @@ void handle_special (struct buffer *buf,
     }
 }
 
-inline int handle_packet (struct buffer *buf, struct tunnel *t,
+int handle_packet (struct buffer *buf, struct tunnel *t,
                           struct call *c)
 {
     int res;
