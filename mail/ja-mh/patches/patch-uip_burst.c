$NetBSD: patch-uip_burst.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/burst.c.orig	2013-03-28 18:11:40.000000000 +0000
+++ uip/burst.c
@@ -11,7 +11,7 @@ static char ident[] = "@(#)$Id: burst.c,
 #include	<locale.h>
 #endif
 
-static	cpybrst(), burst();
+static	cpybrst();
 /*  */
 
 static struct swit switches[] = {
@@ -50,6 +50,8 @@ struct smsg {
 
 /*  */
 
+static void burst (struct smsg *smsgs, int msgnum, int inplace, int quietsw, int verbosw);
+
 /* ARGSUSED */
 
 main (argc, argv)
@@ -185,12 +187,7 @@ char  **argv;
 
 /*  */
 
-static  burst (smsgs, msgnum, inplace, quietsw, verbosw)
-register struct smsg *smsgs;
-int     msgnum,
-        inplace,
-        quietsw,
-        verbosw;
+static void burst (struct smsg *smsgs, int msgnum, int inplace, int quietsw, int verbosw)
 {
     int     i,
             j,
