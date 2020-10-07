$NetBSD: patch-ntpd_refclock__wwvb.c,v 1.2 2020/10/07 09:09:39 sjmulder Exp $

* Changes from NetBSD base w/ Linux fix

--- ntpd/refclock_wwvb.c.orig	2014-12-30 00:29:38.000000000 +0000
+++ ntpd/refclock_wwvb.c
@@ -154,7 +154,7 @@ static	void	wwvb_control	(int, const str
 				 struct refclockstat *, struct peer *);
 #define		WWVB_CONTROL	wwvb_control
 #else
-#define		WWVB_CONTROL	noentry
+#define		WWVB_CONTROL	(void*)noentry
 #endif /* HAVE_PPSAPI */
 
 /*
