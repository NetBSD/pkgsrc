$NetBSD: patch-src_exmove.cpp,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/exmove.cpp.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/exmove.cpp
@@ -15,7 +15,7 @@
 // If the move is legal, the function returns a 1, otherwise 0.
 // Note that the move is made, regardless - so proper precautions
 // need to be taken, if the move might need to be undone
-int position::exec_move(move emove, int ply)
+int position::exec_move(my_move emove, int ply)
 {
   move_t mv = emove.b;
   register int pi;
