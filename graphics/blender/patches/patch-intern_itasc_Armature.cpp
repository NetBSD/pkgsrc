$NetBSD: patch-intern_itasc_Armature.cpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/Armature.cpp.orig	2013-03-18 11:44:56.000000000 +0000
+++ intern/itasc/Armature.cpp
@@ -402,7 +402,7 @@ bool Armature::finalize()
 	m_armlength = 0.0;
 	for (i=0; i<m_neffector; i++) {
 		length = 0.0;
-		KDL::SegmentMap::const_iterator sit = m_tree.getSegment(m_effectors[i].name);
+		KDL::SegmentMap::value_type const *sit = m_tree.getSegmentPtr(m_effectors[i].name);
 		while (sit->first != "root") {
 			Frame tip = sit->second.segment.pose(m_qKdl(sit->second.q_nr));
 			length += tip.p.Norm();
