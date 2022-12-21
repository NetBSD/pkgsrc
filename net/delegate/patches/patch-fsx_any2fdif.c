$NetBSD: patch-fsx_any2fdif.c,v 1.1 2022/12/21 14:41:59 wiz Exp $

Fix compilation on char = signed char systems.

--- fsx/any2fdif.c.orig	2009-01-21 07:09:37.000000000 +0000
+++ fsx/any2fdif.c
@@ -141,7 +141,7 @@ static const char *indexbase = "freyasx/
 #define T_MBOX	6
 
 #define CH_COPYR	0xA9
-static char thru8[32] = {CH_COPYR};
+static unsigned char thru8[32] = {CH_COPYR};
 static int Itype = T_HTML;
 
 typedef struct {
@@ -2350,7 +2350,7 @@ int any2fdif(PCStr(pre),PCStr(strip),PCS
 	ccx_oututf = strcasestr(ccx_outcode,"utf") != 0;
 
 	CCXcreate("*",ccx_outcode,(CCXP)Ccx);
-	CCXthru8((CCXP)Ccx,thru8);
+	CCXthru8((CCXP)Ccx,(char*)thru8);
 	CCXdisable = 0;
 	if( streq(ccx_outcode,"thru") ){
 		CCXdisable = 1;
