$NetBSD: patch-src_lepton_jpgcoder.cc,v 1.1 2016/08/26 17:20:54 joerg Exp $

--- src/lepton/jpgcoder.cc.orig	2016-08-26 14:02:20.988180370 +0000
+++ src/lepton/jpgcoder.cc
@@ -4615,7 +4615,7 @@ int decode_ac_prg_fs( abitreader* huffr,
     // check eobrun
     if ( (*eobrun) > 0 ) {
         for ( bpos = from; bpos <= to; )
-            block[ bpos ] = 0;
+            block[ bpos++ ] = 0;
         (*eobrun)--;
         return from;
     }
