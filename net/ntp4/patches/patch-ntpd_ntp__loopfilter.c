$NetBSD: patch-ntpd_ntp__loopfilter.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/ntp_loopfilter.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpd/ntp_loopfilter.c
@@ -603,7 +603,7 @@ local_clock(
 
 			clock_frequency = direct_freq(fp_offset);
 
-			/* fall through to EVNT_SPIK */
+			/*FALLTHROUGH*/
 
 		/*
 		 * In SPIK state we ignore succeeding outliers until
@@ -614,7 +614,7 @@ local_clock(
 			if (mu < clock_minstep)
 				return (0);
 
-			/* fall through to default */
+			/*FALLTHROUGH*/
 
 		/*
 		 * We get here by default in NSET and FSET states and
