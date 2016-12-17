$NetBSD: patch-igs_show.cc,v 1.1 2016/12/17 23:22:30 joerg Exp $

--- igs/show.cc.orig	2015-12-25 16:59:26.000000000 +0000
+++ igs/show.cc
@@ -359,5 +359,5 @@ void Show::show_score_board(const Board 
 	}
  out:
 	if (is_score) part.add_score(t); // don't delete t
-	else delete t;
+	else delete[] t;
 }
