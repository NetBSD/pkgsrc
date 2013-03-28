$NetBSD: patch-uip_trmsbr.c,v 1.1 2013/03/28 21:31:27 joerg Exp $

--- uip/trmsbr.c.orig	2013-03-28 18:16:11.000000000 +0000
+++ uip/trmsbr.c
@@ -57,7 +57,7 @@ static char termcap[TXTSIZ];
 
 /*  */
 
-static  read_termcap () {
+static void read_termcap (void) {
     register char  *bp,
                    *term;
     char   *cp,
