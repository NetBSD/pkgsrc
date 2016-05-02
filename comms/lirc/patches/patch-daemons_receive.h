$NetBSD: patch-daemons_receive.h,v 1.1 2016/05/02 02:32:14 dholland Exp $

Patch up gcc inline mess.

--- daemons/receive.h~	2011-03-25 22:28:18.000000000 +0000
+++ daemons/receive.h
@@ -39,7 +39,6 @@ static inline lirc_t receive_timeout(lir
 	return 2 * usec < MIN_RECEIVE_TIMEOUT ? MIN_RECEIVE_TIMEOUT : 2 * usec;
 }
 
-inline lirc_t lirc_t_max(lirc_t a, lirc_t b);
 void init_rec_buffer();
 int clear_rec_buffer(void);
 int receive_decode(struct ir_remote *remote, ir_code * prep, ir_code * codep, ir_code * postp, int *repeat_flag,
