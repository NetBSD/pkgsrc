$NetBSD: patch-daemons_transmit.h,v 1.2 2019/06/24 19:01:51 triaxx Exp $

Patch up gcc inline mess.

--- daemons/transmit.h.orig	2011-03-25 22:28:18.000000000 +0000
+++ daemons/transmit.h
@@ -29,7 +29,8 @@ struct sbuf {
 };
 
 void init_send_buffer(void);
-inline void set_bit(ir_code * code, int bit, int data);
+void set_bit(ir_code * code, int bit, int data);
+void send_data(struct ir_remote *remote, ir_code data, int bits, int done);
 int init_send(struct ir_remote *remote, struct ir_ncode *code);
 int init_sim(struct ir_remote *remote, struct ir_ncode *code, int repeat_preset);
 
