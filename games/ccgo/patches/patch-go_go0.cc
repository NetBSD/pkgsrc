$NetBSD: patch-go_go0.cc,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- go/go0.cc.orig	2015-12-25 17:01:53.000000000 +0000
+++ go/go0.cc
@@ -277,7 +277,7 @@ void Board::score_terri(Terri * terri) c
 			}
 		}
 	} while (rr);
-	delete marks;
+	delete[] marks;
 }
 
 void Board::find_terri(int loc, std::vector<int> & group, bool & w_seen, bool & b_seen, Terri * terri, bool * marks) const
@@ -319,7 +319,7 @@ void Board::get_group(int loc, std::vect
 	bool * marks = new bool[r];
 	for (int i = 0; i < r; i ++) marks[i] = false;
 	qi_group(loc, group, b[loc], marks);
-	delete marks;
+	delete[] marks;
 }
 
 void Board::dead_group(int loc, std::vector<int> & group) const
@@ -329,7 +329,7 @@ void Board::dead_group(int loc, std::vec
 	bool * marks = new bool[r];
 	for (int i = 0; i < r; i ++) marks[i] = false;
 	terri_group(loc, b[loc], group, marks);
-	delete marks;
+	delete[] marks;
 }
 
 void Board::terri_group(int loc, State state, std::vector<int> & group, bool * marks) const
