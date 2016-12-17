$NetBSD: patch-go_board.cc,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- go/board.cc.orig	2015-12-25 17:03:20.000000000 +0000
+++ go/board.cc
@@ -323,7 +323,7 @@ void Board::score_terri(State * terri) c
 			}
 		}
 	} while (rr);
-	delete marks;
+	delete[] marks;
 }
 
 void Board::get_group(Loc loc, vector<Loc> & group) const
@@ -333,7 +333,7 @@ void Board::get_group(Loc loc, vector<Lo
 	bool * marks = new bool[r];
 	for (Loc i = 0; i < r; i ++) marks[i] = false;
 	qi_group(loc, group, b[loc], marks);
-	delete marks;
+	delete[] marks;
 }
 
 void Board::dead_group(Loc loc, vector<Loc> & group) const
@@ -343,7 +343,7 @@ void Board::dead_group(Loc loc, vector<L
 	bool * marks = new bool[r];
 	for (Loc i = 0; i < r; i ++) marks[i] = false;
 	terri_group(loc, b[loc], group, marks);
-	delete marks;
+	delete[] marks;
 }
 void Board::find_terri(Loc loc, vector<Loc> & group, bool & w_seen, bool & b_seen, State * terri, bool * marks) const
 // recursively find connected empty space including killed stones
