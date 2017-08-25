$NetBSD: patch-hw_net_e1000.c,v 1.1 2017/08/25 12:39:56 jperkin Exp $

Avoid SEC definition.

--- hw/net/e1000.c.orig	2017-04-20 14:57:00.000000000 +0000
+++ hw/net/e1000.c
@@ -1127,7 +1127,7 @@ static uint32_t (*macreg_readops[])(E100
     getreg(TADV),     getreg(ITR),      getreg(FCRUC),    getreg(IPAV),
     getreg(WUC),      getreg(WUS),      getreg(SCC),      getreg(ECOL),
     getreg(MCC),      getreg(LATECOL),  getreg(COLC),     getreg(DC),
-    getreg(TNCRS),    getreg(SEC),      getreg(CEXTERR),  getreg(RLEC),
+    getreg(TNCRS),    getreg(SEQEC),    getreg(CEXTERR),  getreg(RLEC),
     getreg(XONRXC),   getreg(XONTXC),   getreg(XOFFRXC),  getreg(XOFFTXC),
     getreg(RFC),      getreg(RJC),      getreg(RNBC),     getreg(TSCTFC),
     getreg(MGTPRC),   getreg(MGTPDC),   getreg(MGTPTC),   getreg(GORCL),
@@ -1223,7 +1223,7 @@ static const uint8_t mac_reg_access[0x80
     [FFLT]    = markflag(MAC),    [FFMT]    = markflag(MAC),
     [SCC]     = markflag(MAC),    [FCRUC]   = markflag(MAC),
     [LATECOL] = markflag(MAC),    [COLC]    = markflag(MAC),
-    [SEC]     = markflag(MAC),    [CEXTERR] = markflag(MAC),
+    [SEQEC]   = markflag(MAC),    [CEXTERR] = markflag(MAC),
     [XONTXC]  = markflag(MAC),    [XOFFRXC] = markflag(MAC),
     [RJC]     = markflag(MAC),    [RNBC]    = markflag(MAC),
     [MGTPDC]  = markflag(MAC),    [MGTPTC]  = markflag(MAC),
