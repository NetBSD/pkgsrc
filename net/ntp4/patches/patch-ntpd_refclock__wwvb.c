$NetBSD: patch-ntpd_refclock__wwvb.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/refclock_wwvb.c.orig	2014-12-30 00:29:38.000000000 +0000
+++ ntpd/refclock_wwvb.c
@@ -154,7 +154,8 @@ static	void	wwvb_control	(int, const str
 				 struct refclockstat *, struct peer *);
 #define		WWVB_CONTROL	wwvb_control
 #else
-#define		WWVB_CONTROL	noentry
+#define		WWVB_CONTROL	(void)(*)
+noentry
 #endif /* HAVE_PPSAPI */
 
 /*
