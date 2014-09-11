$NetBSD: patch-src_hash.cpp,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/hash.cpp.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/hash.cpp
@@ -211,7 +211,7 @@ void put_hash(h_code (*h_key), int score
 //--------------------------------------------
 // function to find and return a hash entry
 //--------------------------------------------
-int get_hash(h_code (*h_key), int *hflag, int *hdepth, int *mate_ext, move *gmove, int ply)
+int get_hash(h_code (*h_key), int *hflag, int *hdepth, int *mate_ext, my_move *gmove, int ply)
 {
   hash_bucket *h; int best_depth_rec = -1; 
 
