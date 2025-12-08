$NetBSD: patch-dynPenOp.c,v 1.1 2025/12/08 21:05:41 vins Exp $

dynFinish is declared as double, but always used as int.

--- dynPenOp.c.orig	2021-01-16 11:57:53.000000000 +0000
+++ dynPenOp.c
@@ -35,7 +35,8 @@
 
 #define XTIMEOUT 20
 
-double dynWidth = 10, dynMass = 600, dynDrag = 15, dynFinish = 0;
+double dynWidth = 10, dynMass = 600, dynDrag = 15;
+int dynFinish = 0;
 
 typedef struct {
 	double	startx, starty;
