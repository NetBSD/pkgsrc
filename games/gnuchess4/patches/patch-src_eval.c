$NetBSD: patch-src_eval.c,v 1.1 2012/12/20 22:02:13 joerg Exp $

--- src/eval.c.orig	2012-12-20 19:23:42.000000000 +0000
+++ src/eval.c
@@ -173,7 +173,7 @@ SHORT pscore[2];
 #ifdef CACHE
 struct etable *etab[2];
 
-inline void
+static inline void
 PutInEETable (SHORT side,int score)
 
 /*
@@ -199,7 +199,7 @@ PutInEETable (SHORT side,int score)
     return;
 }
 
-inline int
+static inline int
 CheckEETable (SHORT side)
 
 /* Check the static cache for an entry  */
@@ -213,7 +213,7 @@ CheckEETable (SHORT side)
     return false;
 }
 
-inline int
+static inline int
 ProbeEETable (SHORT side, SHORT *score)
 
 /* Get an evaluation from the static cache */
@@ -265,7 +265,7 @@ ProbeEETable (SHORT side, SHORT *score)
  * PieceCnt[side] - just what it says
  */
 
-inline
+static inline
 int
 ScoreKPK (SHORT side,
 	  SHORT winner,
@@ -310,7 +310,7 @@ ScoreKPK (SHORT side,
     return (s);
 }
 
-inline
+static inline
 SHORT
 ScoreLoneKing (SHORT side)
 /*
@@ -353,7 +353,7 @@ ScoreLoneKing (SHORT side)
   return ((side == winner) ? s : -s);
 }
 
-inline
+static inline
 int
 ScoreKBNK (SHORT winner, SHORT king1, SHORT king2)
 /*
@@ -389,7 +389,7 @@ SHORT dist_ (SHORT f1, SHORT r1, SHORT f
   return distdata [ f1-9+8*r1 ][ f2-9+8*r2 ];
 }
 
-inline 
+static inline 
 int  
 ScoreK1PK (SHORT side,
            SHORT winner,
@@ -714,7 +714,7 @@ evaluate (register SHORT side,
     return (s);
 }
 
-inline
+static inline
 int
 BRscan (register SHORT sq, SHORT *mob)
 
@@ -777,7 +777,7 @@ BRscan (register SHORT sq, SHORT *mob)
     return s;
 }
 
-inline
+static inline
 SHORT
 KingScan (register SHORT sq)
 
@@ -871,7 +871,7 @@ KingScan (register SHORT sq)
 }
 
 
-inline
+static inline
 int
 trapped (register SHORT sq)
 
@@ -1023,7 +1023,7 @@ PawnValue (register SHORT sq, SHORT side
     return (s);
 }
 
-inline
+static inline
 int
 KnightValue (register SHORT sq, register SHORT side)
 
@@ -1052,7 +1052,7 @@ KnightValue (register SHORT sq, register
     return (s);
 }
 
-inline
+static inline
 int
 BishopValue (register SHORT sq, register SHORT side)
 
@@ -1085,7 +1085,7 @@ BishopValue (register SHORT sq, register
     return (s);
 }
 
-inline
+static inline
 int
 RookValue (register SHORT sq, register SHORT side)
 
@@ -1127,7 +1127,7 @@ RookValue (register SHORT sq, register S
     return (s);
 }
 
-inline
+static inline
 int
 QueenValue (register SHORT sq, register SHORT side)
 
@@ -1158,7 +1158,7 @@ QueenValue (register SHORT sq, register 
     return (s);
 }
 
-inline
+static inline
 int
 KingValue (register SHORT sq, register SHORT side)
 
