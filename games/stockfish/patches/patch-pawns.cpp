$NetBSD: patch-pawns.cpp,v 1.2 2022/04/25 15:24:31 tnn Exp $

date: 2019-12-20 01:00:55 +0100;  author: joerg;  state: Exp;  commitid: QhSAW31NXzINnnPB;
Fix popcount conflict on NetBSD. Avoid LTO and 32bit binaries on NetBSD.

--- pawns.cpp.orig	2019-12-19 22:50:55.102229747 +0000
+++ pawns.cpp
@@ -223,8 +223,8 @@ Entry* probe(const Position& pos) {
 
   e->key = key;
   e->score = evaluate<WHITE>(pos, e) - evaluate<BLACK>(pos, e);
-  e->asymmetry = popcount(e->semiopenFiles[WHITE] ^ e->semiopenFiles[BLACK]);
-  e->openFiles = popcount(e->semiopenFiles[WHITE] & e->semiopenFiles[BLACK]);
+  e->asymmetry = popcount(Bitboard(e->semiopenFiles[WHITE] ^ e->semiopenFiles[BLACK]));
+  e->openFiles = popcount(Bitboard(e->semiopenFiles[WHITE] & e->semiopenFiles[BLACK]));
   return e;
 }
 
