$NetBSD: patch-extern_rangetree_range__tree.hh,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- extern/rangetree/range_tree.hh.orig	2013-11-20 21:28:30.000000000 +0000
+++ extern/rangetree/range_tree.hh
@@ -39,9 +39,9 @@ struct RangeTree {
 			return max < v.min;
 		}
 
-		const T min;
-		const T max;
-		const bool single;
+		T min;
+		T max;
+		bool single;
 	};
 
 	typedef std::set<Range> Tree;
