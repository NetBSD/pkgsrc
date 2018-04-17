$NetBSD: patch-chardev_char-mux.c,v 1.1 2018/04/17 20:02:14 gson Exp $

Fix ctrl-a b again.  This is a backport of qemu git commit
1b2503fcf7b5932c5a3779ca2ceb92bd403c4ee7.

--- chardev/char-mux.c.orig	2018-02-14 21:53:22.000000000 +0000
+++ chardev/char-mux.c
@@ -295,6 +295,7 @@ void mux_set_focus(Chardev *chr, int foc
     }
 
     d->focus = focus;
+    chr->be = d->backends[focus];
     mux_chr_send_event(d, d->focus, CHR_EVENT_MUX_IN);
 }
 
