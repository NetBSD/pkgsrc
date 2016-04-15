$NetBSD: patch-src_vmm_io_vhpet.c,v 1.1 2016/04/15 14:13:21 youri Exp $

Cast to void * to print address.

--- src/vmm/io/vhpet.c.orig	2015-07-27 02:07:09.000000000 +0000
+++ src/vmm/io/vhpet.c
@@ -291,7 +291,7 @@ vhpet_handler(void *a)
 	callout_deactivate(callout);
 
 	if (!vhpet_counter_enabled(vhpet))
-		xhyve_abort("vhpet(%p) callout with counter disabled\n", vhpet);
+		xhyve_abort("vhpet(%p) callout with counter disabled\n", (void *)vhpet);
 
 	counter = vhpet_counter(vhpet, &now);
 	vhpet_start_timer(vhpet, n, counter, now);
