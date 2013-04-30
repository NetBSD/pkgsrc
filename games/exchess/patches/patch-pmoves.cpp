$NetBSD: patch-pmoves.cpp,v 1.1 2013/04/30 22:20:58 joerg Exp $

--- pmoves.cpp.orig	2013-04-30 20:06:41.000000000 +0000
+++ pmoves.cpp
@@ -10,7 +10,7 @@
 
 extern unsigned int history[64][64];           // history table
 extern int killer1[2], killer2[2], killer3[2];
-extern move hmove;                              // hash move
+extern my_move hmove;                              // hash move
 extern int taxi_cab[64][64];
 extern int stage;
 extern int check_table[64][64], knight_check_table[64][64];
