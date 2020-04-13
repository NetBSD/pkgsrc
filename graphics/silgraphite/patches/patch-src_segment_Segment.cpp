$NetBSD: patch-src_segment_Segment.cpp,v 1.1 2020/04/13 19:16:47 joerg Exp $

--- src/segment/Segment.cpp.orig	2020-04-12 22:06:15.425721206 +0000
+++ src/segment/Segment.cpp
@@ -575,7 +575,13 @@ void Segment::SwapWith(Segment * pgrseg)
 	int crefThis = m_cref;
 	int crefOther = pgrseg->m_cref;
 
+#ifdef _LIBCPP_VERSION
+	Segment tmp(*this);
+	*pgrseg = *this;
+	*this = tmp;
+#else
 	std::swap(*this, *pgrseg);
+#endif
 
 	m_cref = crefThis;
 	pgrseg->m_cref = crefOther;
