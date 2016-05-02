$NetBSD: patch-daemons_transmit.c,v 1.1 2016/05/02 02:32:14 dholland Exp $

Patch up gcc inline mess.

--- daemons/transmit.c~	2011-03-25 22:28:18.000000000 +0000
+++ daemons/transmit.c
@@ -27,7 +27,7 @@ struct sbuf send_buffer;
 static void send_signals(lirc_t * signals, int n);
 static int init_send_or_sim(struct ir_remote *remote, struct ir_ncode *code, int sim, int repeat_preset);
 
-inline void set_bit(ir_code * code, int bit, int data)
+void set_bit(ir_code * code, int bit, int data)
 {
 	(*code) &= ~((((ir_code) 1) << bit));
 	(*code) |= ((ir_code) (data ? 1 : 0) << bit);
