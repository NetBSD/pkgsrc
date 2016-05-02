$NetBSD: patch-daemons_receive.c,v 1.1 2016/05/02 02:32:14 dholland Exp $

Patch up gcc inline mess.

--- daemons/receive.c~	2011-03-25 22:28:18.000000000 +0000
+++ daemons/receive.c
@@ -25,12 +25,12 @@ extern struct ir_remote *last_remote;
 
 struct rbuf rec_buffer;
 
-inline lirc_t lirc_t_max(lirc_t a, lirc_t b)
+static inline lirc_t lirc_t_max(lirc_t a, lirc_t b)
 {
 	return (a > b ? a : b);
 }
 
-inline void set_pending_pulse(lirc_t deltap)
+static inline void set_pending_pulse(lirc_t deltap)
 {
 	LOGPRINTF(5, "pending pulse: %lu", deltap);
 	rec_buffer.pendingp = deltap;
@@ -378,7 +378,7 @@ inline int expectzero(struct ir_remote *
 	return (1);
 }
 
-inline lirc_t sync_rec_buffer(struct ir_remote * remote)
+static inline lirc_t sync_rec_buffer(struct ir_remote * remote)
 {
 	int count;
 	lirc_t deltas, deltap;
@@ -414,7 +414,7 @@ inline lirc_t sync_rec_buffer(struct ir_
 	return (deltas);
 }
 
-inline int get_header(struct ir_remote *remote)
+static inline int get_header(struct ir_remote *remote)
 {
 	if (is_rcmm(remote)) {
 		lirc_t deltap, deltas, sum;
@@ -524,7 +524,7 @@ inline int get_gap(struct ir_remote *rem
 	return (1);
 }
 
-inline int get_repeat(struct ir_remote *remote)
+static inline int get_repeat(struct ir_remote *remote)
 {
 	if (!get_lead(remote))
 		return (0);
