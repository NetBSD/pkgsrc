$NetBSD: patch-src_hash.h,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid 'move' conflict.

--- src/hash.h.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/hash.h
@@ -26,7 +26,7 @@
 struct hash_rec
 {
   h_code hr_key;
-  move hr_hmove;
+  my_move hr_hmove;
   int16_t hr_score;
   char hr_depth;   // note that stored depths cannot be larger than 127
   unsigned char hr_data;  // first 5 bits = id, next 2 = flag, next 1 = mate_ext
@@ -132,7 +132,7 @@ void open_hash();
 void close_hash();
 void set_hash_size(unsigned int Mbytes);
 void put_hash(h_code *h_key, int score, int alpha, int beta, int depth, int hmove, int mate_ext, int h_id, int ply);
-int get_hash(h_code *h_key, int *hflag, int *hdepth, int *mate_ext, move *gmove, int ply);
+int get_hash(h_code *h_key, int *hflag, int *hdepth, int *mate_ext, my_move *gmove, int ply);
 int get_move(h_code *h_key);
 int put_move(h_code h_key, int putmove, int h_id);
 
