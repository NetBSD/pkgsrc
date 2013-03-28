$NetBSD: patch-uip_ali.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/ali.c.orig	2013-03-28 18:03:52.000000000 +0000
+++ uip/ali.c
@@ -47,6 +47,8 @@ static struct swit switches[] = {
 
 static	int     pos = 1;
 
+static void print_aka (char *p, int list, int margin);
+
 extern struct aka  *akahead;
 
 /*  */
@@ -180,10 +182,7 @@ char   *argv[];
 
 /*  */
 
-print_aka (p, list, margin)
-register char  *p;
-int     list,
-        margin;
+static void print_aka (char *p, int list, int margin)
 {
     register char   c;
 #ifdef JAPAN
