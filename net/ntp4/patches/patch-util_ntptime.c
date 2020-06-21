$NetBSD: patch-util_ntptime.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- util/ntptime.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ util/ntptime.c
@@ -98,7 +98,7 @@ main(
 	struct timex ntx, _ntx;
 	int	times[20] = { 0 };
 	double ftemp, gtemp, htemp;
-	double nscale = 1.0;			/* assume usec scale for now */
+	volatile double nscale = 1.0;			/* assume usec scale for now */
 	long time_frac;				/* ntv.time.tv_frac_sec (us/ns) */
 	l_fp ts;
 	volatile unsigned ts_mask = TS_MASK_US;		/* defaults to 20 bits (us) */
