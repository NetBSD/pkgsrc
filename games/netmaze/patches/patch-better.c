$NetBSD: patch-better.c,v 1.2 2013/03/25 01:59:03 dholland Exp $

- use standard headers
- define BIGGEST to something
- silence some warnings
- don't use -1 to access an array of player info

--- better.c.orig	1994-04-16 16:18:30.000000000 +0000
+++ better.c
@@ -12,11 +12,14 @@
 */
 
 #include <math.h>
+#include <limits.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "netmaze.h"
 #include "better.h"
 
-#define BIGGEST			/* groesster long-wert */
+#define BIGGEST		LONG_MAX	/* groesster long-wert */
 #define NERVOUS 50000000 	/* ab hier sucht BB sein Opfer */
 #define TODESRADIUS1 7000000
 #define TODESRADIUS 15000000   
@@ -102,7 +105,7 @@ geht so einigermassen... */
 int k_sichtbar(long x1,long y1,long  x2,long y2)
 {
 	int x1q,y1q,x2q,y2q,xqdiff,yqdiff;
-	int x_count,y_count,vstep,hstep,hstep1,vstep1;
+	int x_count,y_count,vstep,hstep;
 	long xdiff,ydiff,xl_count,yl_count,xl_step,yl_step;
 	float xy,yx;
 
@@ -308,7 +311,6 @@ static long target_angle(PLAYER* them){
     int mx,my;
     int tx,ty;
     int dx,dy;
-    int angle, diff;
     PLAYER* me= &(sm->playfeld[ownnumber]);
 
 /*  mx = (int) ((me->x) >> 24);
@@ -356,9 +358,8 @@ void angl(int opfer){
 /* wird bei jedem 'tick' aufgerufen. das herz von BB. bb - Falsch BB hat kein Herz . JK*/
 
 int own_action(void){
-  static touchie=0;
-  int opfer, winkel, owinkel, hwinkel, lwinkel, alt_opfer;
-  long x_dist,y_dist,nx_dist,ny_dist,lx_dist,ly_dist,hx_dist,hy_dist;
+  static int touchie=0;
+  int opfer;
   long i;
 
   if (!(sm->playfeld[ownnumber].alive)){ /* I'm dead , wooouueeehhhh */
@@ -368,7 +369,7 @@ int own_action(void){
       if (sm->playfeld[ownnumber].ownkiller==robodat.freund){ /* ts, ts */
 	robodat.exfreund=robodat.freund;
 	robodat.freund=-1;
-	fprintf(stderr,"No more Mister Nice Guy, %s!",sm->playfeld[robodat.freund].name);
+	fprintf(stderr,"No more Mister Nice Guy, %s!",sm->playfeld[robodat.exfreund].name);
 	sprintf(sm->owncomment,"%s, you fucking traitor pig : die scum!",robodat.freundname);
 	send_owncomment();
       };
