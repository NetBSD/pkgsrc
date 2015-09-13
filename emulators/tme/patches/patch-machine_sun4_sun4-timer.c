$NetBSD: patch-machine_sun4_sun4-timer.c,v 1.1 2015/09/13 15:08:09 joerg Exp $

--- machine/sun4/sun4-timer.c.orig	2015-09-03 14:47:23.000000000 +0000
+++ machine/sun4/sun4-timer.c
@@ -44,8 +44,8 @@ _TME_RCSID("$Id: sun4-timer.c,v 1.3 2010
 
 /* real sun4/4c timer bits: */
 #define TME_SUN4_32_TIMER_LIMIT		TME_BIT(31)
-#define	TME_SUN44C_TIMER_MASK		(0x7ffffc00)
-#define	TME_SUN4M_TIMER_MASK		(0x7ffffe00)
+#define	TME_SUN44C_TIMER_MASK		(0x7ffffc00U)
+#define	TME_SUN4M_TIMER_MASK		(0x7ffffe00U)
 
 /* define this to track interrupt rates, reporting once every N
    seconds: */
