$NetBSD: patch-src_score.cpp,v 1.1 2014/09/11 16:59:16 jperkin Exp $

Avoid overloaded function ambiguity.

--- src/score.cpp.orig	2014-08-17 11:03:08.000000000 +0000
+++ src/score.cpp
@@ -67,7 +67,7 @@ int position::score_pos(game_rec *gr, ts
      int TRADES = AVERAGE_SCORE(TRADES_EARLY, TRADES_LATE);
      // bonus scales current material score by the ratio of the pawn count
      //  to the total piece count
-     score += (TRADES*score*(pawn_count-piece_count))/(500*sqrt(pawn_count+piece_count));
+     score += (TRADES*score*(pawn_count-piece_count))/(500*sqrt((float)pawn_count+piece_count));
    }
 
 /*+++++++++++++++++++++++++++++++
