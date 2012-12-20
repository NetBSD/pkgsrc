$NetBSD: patch-pgmain_pg.c,v 1.1 2012/12/20 21:51:39 joerg Exp $

--- pgmain/pg.c.orig	2012-12-20 18:24:02.000000000 +0000
+++ pgmain/pg.c
@@ -41,7 +41,8 @@ static float baddata;       /* actual ba
 static float dott(),cinty(),cintx(),maglim();
 static void panic(),rest(),draw(),mark(),conv(),norm(),mlabel();
 static int survey(),cside(),insect(),conto(),vplot(),axes(),
-     grid(),kfill(),nfill(),pfill(),xx(),pdraw();
+     grid(),kfill(),nfill(),pfill(),pdraw();
+static void xx();
 
 /* global declarations -- for communication with the low level routines */
 FILE *pgraf;         /* metacode input file */
@@ -1263,7 +1264,7 @@ float zv[6],z,vl[2][4],xs,xt,ys,yt,rys,r
   }
 }
 
-static int xx(ax,ay,bx,by,ltype)
+static void xx(ax,ay,bx,by,ltype)
 int ltype;
 float ax,ay, bx,by;
 {
@@ -1292,7 +1293,7 @@ float ax,ay, bx,by;
      by>=y1 &&bx<=x2 && by<=y2) {
     pgmove(ax,ay);
     pgdraw(bx,by,ltype);
-    return(0);
+    return;
   }
   whr = insect(ax,ay,bx,by);
 
@@ -1314,7 +1315,7 @@ float ax,ay, bx,by;
     y -= ((cy)/(cx))*(outx-x1);
   }
   if(x>x2|| y>y2 || x<x1 || y<y1) return;
-  if (whr == 10) return(0);
+  if (whr == 10) return;
   if(ax>x2 || ax<x1 || ay<y1 || ay>y2){
     pgmove(x,y);
     pgdraw(bx,by,ltype);
