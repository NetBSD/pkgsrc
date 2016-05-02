$NetBSD: patch-daemons_transmit.h,v 1.1 2016/05/02 02:32:14 dholland Exp $

Patch up gcc inline mess.

--- daemons/transmit.h~	2011-03-25 22:28:18.000000000 +0000
+++ daemons/transmit.h
@@ -29,7 +29,7 @@ struct sbuf {
 };
 
 void init_send_buffer(void);
-inline void set_bit(ir_code * code, int bit, int data);
+void set_bit(ir_code * code, int bit, int data);
 int init_send(struct ir_remote *remote, struct ir_ncode *code);
 int init_sim(struct ir_remote *remote, struct ir_ncode *code, int repeat_preset);
 
