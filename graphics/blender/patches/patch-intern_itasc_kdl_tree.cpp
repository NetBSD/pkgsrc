$NetBSD: patch-intern_itasc_kdl_tree.cpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/tree.cpp.orig	2012-06-03 12:00:41.000000000 +0000
+++ intern/itasc/kdl/tree.cpp
@@ -64,7 +64,7 @@ bool Tree::addSegment(const Segment& seg
         return false;
     pair<SegmentMap::iterator, bool> retval;
     //insert new element
-	TreeElement elem(segment, parent, nrOfJoints);
+	TreeElement elem(segment, *parent, nrOfJoints);
 	std::pair<std::string, TreeElement> val(segment_name, elem);
 
     retval = segments.insert(val);
