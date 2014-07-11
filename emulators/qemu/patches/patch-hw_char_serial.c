$NetBSD: patch-hw_char_serial.c,v 1.1 2014/07/11 19:15:08 gson Exp $

Part of fix for qemu bug 1335444, aka PR 48071.  From Kirill Batuzov,
backported to 2.0 by gson.

--- hw/char/serial.c.orig	2014-04-17 13:44:44.000000000 +0000
+++ hw/char/serial.c
@@ -223,37 +223,42 @@ static gboolean serial_xmit(GIOChannel *
 {
     SerialState *s = opaque;
 
-    if (s->tsr_retry <= 0) {
-        if (s->fcr & UART_FCR_FE) {
-            if (fifo8_is_empty(&s->xmit_fifo)) {
+    do {
+        if (s->tsr_retry <= 0) {
+            if (s->fcr & UART_FCR_FE) {
+                if (fifo8_is_empty(&s->xmit_fifo)) {
+                    return FALSE;
+                }
+                s->tsr = fifo8_pop(&s->xmit_fifo);
+                if (!s->xmit_fifo.num) {
+                    s->lsr |= UART_LSR_THRE;
+                }
+            } else if ((s->lsr & UART_LSR_THRE)) {
                 return FALSE;
-            }
-            s->tsr = fifo8_pop(&s->xmit_fifo);
-            if (!s->xmit_fifo.num) {
+            } else {
+                s->tsr = s->thr;
                 s->lsr |= UART_LSR_THRE;
+                s->lsr &= ~UART_LSR_TEMT;
             }
-        } else if ((s->lsr & UART_LSR_THRE)) {
-            return FALSE;
-        } else {
-            s->tsr = s->thr;
-            s->lsr |= UART_LSR_THRE;
-            s->lsr &= ~UART_LSR_TEMT;
         }
-    }
 
-    if (s->mcr & UART_MCR_LOOP) {
-        /* in loopback mode, say that we just received a char */
-        serial_receive1(s, &s->tsr, 1);
-    } else if (qemu_chr_fe_write(s->chr, &s->tsr, 1) != 1) {
-        if (s->tsr_retry >= 0 && s->tsr_retry < MAX_XMIT_RETRY &&
-            qemu_chr_fe_add_watch(s->chr, G_IO_OUT, serial_xmit, s) > 0) {
-            s->tsr_retry++;
-            return FALSE;
+        if (s->mcr & UART_MCR_LOOP) {
+            /* in loopback mode, say that we just received a char */
+            serial_receive1(s, &s->tsr, 1);
+        } else if (qemu_chr_fe_write(s->chr, &s->tsr, 1) != 1) {
+            if (s->tsr_retry >= 0 && s->tsr_retry < MAX_XMIT_RETRY &&
+                qemu_chr_fe_add_watch(s->chr, G_IO_OUT|G_IO_HUP,
+                                      serial_xmit, s) > 0) {
+                s->tsr_retry++;
+                return FALSE;
+            }
+            s->tsr_retry = 0;
+        } else {
+            s->tsr_retry = 0;
         }
-        s->tsr_retry = 0;
-    } else {
-        s->tsr_retry = 0;
-    }
+        /* Transmit another byte if it is already available. It is only
+           possible when FIFO is enabled and not empty. */
+    } while ((s->fcr & UART_FCR_FE) && !fifo8_is_empty(&s->xmit_fifo));
 
     s->last_xmit_ts = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);
 
@@ -293,7 +298,9 @@ static void serial_ioport_write(void *op
             s->thr_ipending = 0;
             s->lsr &= ~UART_LSR_THRE;
             serial_update_irq(s);
-            serial_xmit(NULL, G_IO_OUT, s);
+            if (s->tsr_retry <= 0) {
+                serial_xmit(NULL, G_IO_OUT, s);
+            }
         }
         break;
     case 1:
