$NetBSD: patch-uip_conflict.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/conflict.c.orig	2013-03-28 18:42:59.000000000 +0000
+++ uip/conflict.c
@@ -23,6 +23,10 @@ static char ident[] = "@(#)$Id: conflict
 #define	NDIRS	100
 #define	NGRPS	100
 
+void setup (void);
+
+static void mdrop(char *drop);
+
 /*  */
 
 static struct swit switches[] = {
@@ -299,8 +303,7 @@ maildrops () 
 }
 
 
-mdrop(drop)
-register char *drop;
+static void mdrop(char *drop)
 {
     register int    hit = 0;
 #ifdef SYS5DIR
@@ -346,7 +349,7 @@ register char   *s;
 
 /*  */
 
-setup () {
+void setup (void) {
     int     fd,
             pd[2];
 
