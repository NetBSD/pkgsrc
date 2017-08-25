$NetBSD: patch-hw_net_e1000__regs.h,v 1.1 2017/08/25 12:39:56 jperkin Exp $

Avoid SEC definition.

--- hw/net/e1000_regs.h.orig	2017-04-20 14:57:00.000000000 +0000
+++ hw/net/e1000_regs.h
@@ -260,7 +260,7 @@
 #define E1000_COLC     0x04028  /* Collision Count - R/clr */
 #define E1000_DC       0x04030  /* Defer Count - R/clr */
 #define E1000_TNCRS    0x04034  /* TX-No CRS - R/clr */
-#define E1000_SEC      0x04038  /* Sequence Error Count - R/clr */
+#define E1000_SEQEC    0x04038  /* Sequence Error Count - R/clr */
 #define E1000_CEXTERR  0x0403C  /* Carrier Extension Error Count - R/clr */
 #define E1000_RLEC     0x04040  /* Receive Length Error Count - R/clr */
 #define E1000_XONRXC   0x04048  /* XON RX Count - R/clr */
