$NetBSD: patch-uip_aliasbr.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/aliasbr.c.orig	2013-03-28 18:04:32.000000000 +0000
+++ uip/aliasbr.c
@@ -26,7 +26,7 @@ static char   *scanp (), *getp (), *seek
 static struct aka *akalloc ();
 static struct home *hmalloc ();
 
-static		add_aka();
+static void add_aka (struct aka *ak, char *pp);
 static int	aleq(), addfile(), addgroup(), addmember(), addall();
 
 #ifndef	__STDC__
@@ -474,9 +474,7 @@ register char   *addrs;
 
 /*  */
 
-static	add_aka (ak, pp)
-register struct aka *ak;
-register char   *pp;
+static void add_aka (struct aka *ak, char *pp)
 {
     register struct adr *ad,
 			*ld;
