$NetBSD: patch-ntpd_refclock__jjy.c,v 1.2 2020/08/15 02:09:25 tnn Exp $

* Changes from NetBSD base.

--- ntpd/refclock_jjy.c.orig	2020-06-23 09:17:30.000000000 +0000
+++ ntpd/refclock_jjy.c
@@ -1022,7 +1022,7 @@ static void
 jjy_synctime ( struct peer *peer, struct refclockproc *pp, struct jjyunit *up )
 {
 
-	char	sLog [ 80 ], cStatus ;
+	char	sLog [ 192 ], cStatus ;
 	const char	*pStatus ;
 
 	pp->year   = up->year ;
@@ -2737,7 +2737,7 @@ static int
 jjy_start_telephone ( int unit, struct peer *peer, struct jjyunit *up )
 {
 
-	char	sLog [ 80 ], sFirstThreeDigits [ 4 ] ;
+	char	sLog [ 192 ], sFirstThreeDigits [ 4 ] ;
 	int	iNumberOfDigitsOfPhoneNumber, iCommaCount, iCommaPosition ;
 	size_t  i ;
 	size_t	iFirstThreeDigitsCount ;
