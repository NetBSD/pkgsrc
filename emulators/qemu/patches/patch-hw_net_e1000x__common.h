$NetBSD: patch-hw_net_e1000x__common.h,v 1.1 2017/08/25 12:39:56 jperkin Exp $

Avoid SEC definition.

--- hw/net/e1000x_common.h.orig	2017-04-20 14:57:00.000000000 +0000
+++ hw/net/e1000x_common.h
@@ -40,7 +40,7 @@ enum {
     defreg(VFTA),    defreg(VET),     defreg(RDTR),    defreg(RADV),
     defreg(TADV),    defreg(ITR),     defreg(SCC),     defreg(ECOL),
     defreg(MCC),     defreg(LATECOL), defreg(COLC),    defreg(DC),
-    defreg(TNCRS),   defreg(SEC),     defreg(CEXTERR), defreg(RLEC),
+    defreg(TNCRS),   defreg(SEQEC),   defreg(CEXTERR), defreg(RLEC),
     defreg(XONRXC),  defreg(XONTXC),  defreg(XOFFRXC), defreg(XOFFTXC),
     defreg(FCRUC),   defreg(AIT),     defreg(TDFH),    defreg(TDFT),
     defreg(TDFHS),   defreg(TDFTS),   defreg(TDFPC),   defreg(WUC),
