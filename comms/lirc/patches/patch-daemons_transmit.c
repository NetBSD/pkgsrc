$NetBSD: patch-daemons_transmit.c,v 1.2 2019/06/24 19:01:51 triaxx Exp $

Patch up gcc inline mess.

--- daemons/transmit.c.orig	2011-03-25 22:28:18.000000000 +0000
+++ daemons/transmit.c
@@ -27,7 +27,7 @@ struct sbuf send_buffer;
 static void send_signals(lirc_t * signals, int n);
 static int init_send_or_sim(struct ir_remote *remote, struct ir_ncode *code, int sim, int repeat_preset);
 
-inline void set_bit(ir_code * code, int bit, int data)
+void set_bit(ir_code * code, int bit, int data)
 {
 	(*code) &= ~((((ir_code) 1) << bit));
 	(*code) |= ((ir_code) (data ? 1 : 0) << bit);
@@ -179,7 +179,7 @@ inline void send_trail(struct ir_remote
 	}
 }
 
-inline void send_data(struct ir_remote *remote, ir_code data, int bits, int done)
+void send_data(struct ir_remote *remote, ir_code data, int bits, int done)
 {
 	int i;
 	int all_bits = bit_count(remote);
