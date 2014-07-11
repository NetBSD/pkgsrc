$NetBSD: patch-qemu-char.c,v 1.1 2014/07/11 19:15:08 gson Exp $

Part of fix for qemu bug 1335444, aka PR 48071.  From Kirill Batuzov.

--- qemu-char.c.orig	2014-04-17 13:44:45.000000000 +0000
+++ qemu-char.c
@@ -519,6 +519,12 @@ static Notifier muxes_realize_notify = {
     .notify = muxes_realize_done,
 };
 
+static GSource *mux_chr_add_watch(CharDriverState *s, GIOCondition cond)
+{
+    MuxDriver *d = s->opaque;
+    return d->drv->chr_add_watch(d->drv, cond);
+}
+
 static CharDriverState *qemu_chr_open_mux(CharDriverState *drv)
 {
     CharDriverState *chr;
@@ -535,6 +541,9 @@ static CharDriverState *qemu_chr_open_mu
     chr->chr_accept_input = mux_chr_accept_input;
     /* Frontend guest-open / -close notification is not support with muxes */
     chr->chr_set_fe_open = NULL;
+    if (drv->chr_add_watch) {
+        chr->chr_add_watch = mux_chr_add_watch;
+    }
     /* only default to opened state if we've realized the initial
      * set of muxes
      */
