$NetBSD: patch-ntpd_refclock__jjy.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/refclock_jjy.c.orig	2018-02-27 15:15:27.000000000 +0000
+++ ntpd/refclock_jjy.c
@@ -1010,7 +1010,7 @@ static void
 jjy_synctime ( struct peer *peer, struct refclockproc *pp, struct jjyunit *up )
 {
 
-	char	sLog [ 80 ], cStatus ;
+	char	sLog [ 192 ], cStatus ;
 	const char	*pStatus ;
 
 	pp->year   = up->year ;
@@ -1165,7 +1165,7 @@ jjy_receive_tristate_jjy01 ( struct recv
 	struct peer	    *peer;
 
 	char *		pBuf ;
-	char		sLog [ 100 ] ;
+	char		sLog [ 192 ] ;
 	int 		iLen ;
 	int 		rc ;
 
@@ -1461,7 +1461,7 @@ jjy_receive_cdex_jst2000 ( struct recvbu
 	struct refclockproc *pp ;
 	struct peer         *peer ;
 
-	char	*pBuf, sLog [ 100 ] ;
+	char	*pBuf, sLog [ 192 ] ;
 	int 	iLen ;
 	int 	rc ;
 
@@ -2344,7 +2344,7 @@ jjy_receive_seiko_tsys_tdc_300 ( struct 
 	struct refclockproc	*pp ;
 	struct jjyunit		*up ;
 
-	char	*pBuf, sLog [ 100 ] ;
+	char	*pBuf, sLog [ 192 ] ;
 	int	iLen, i ;
 	int	rc, iWeekday ;
 	time_t	now ;
@@ -2693,7 +2693,7 @@ static int
 jjy_start_telephone ( int unit, struct peer *peer, struct jjyunit *up )
 {
 
-	char	sLog [ 80 ], sFirstThreeDigits [ 4 ] ;
+	char	sLog [ 192 ], sFirstThreeDigits [ 4 ] ;
 	int	iNumberOfDigitsOfPhoneNumber, iCommaCount, iCommaPosition ;
 	size_t  i ;
 	size_t	iFirstThreeDigitsCount ;
@@ -3402,7 +3402,7 @@ teljjy_conn_data ( struct peer *peer, st
 
 	char	*pBuf ;
 	int	iLen, rc ;
-	char	sLog [ 80 ] ;
+	char	sLog [ 192 ] ;
 	char	bAdjustment ;
 
 
