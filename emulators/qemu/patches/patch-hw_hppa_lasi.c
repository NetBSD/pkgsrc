$NetBSD: patch-hw_hppa_lasi.c,v 1.1 2020/05/10 11:33:23 skrll Exp $

--- hw/hppa/lasi.c.orig	2020-04-28 16:49:24.000000000 +0000
+++ hw/hppa/lasi.c
@@ -172,8 +172,7 @@ static MemTxResult lasi_chip_write_with_
         /* read-only.  */
         break;
     case LASI_IMR:
-        s->imr = val;  /* 0x20 ?? */
-        assert((val & LASI_IRQ_BITS) == val);
+        s->imr = val & LASI_IRQ_BITS;
         break;
     case LASI_IPR:
         /* Any write to IPR clears the register. */
