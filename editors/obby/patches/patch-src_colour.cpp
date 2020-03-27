$NetBSD: patch-src_colour.cpp,v 1.1 2020/03/27 20:58:12 joerg Exp $

--- src/colour.cpp.orig	2020-03-27 18:01:51.643167816 +0000
+++ src/colour.cpp
@@ -47,9 +47,9 @@ unsigned int obby::colour::get_blue() co
 bool obby::colour::similar_colour(const colour& colour) const
 {
 	// TODO: Convert to HSV for better checking
-	return abs(m_red - colour.m_red) +
-	       abs(m_green - colour.m_green) +
-	       abs(m_blue - colour.m_blue) < 32;
+	return abs(int(m_red - colour.m_red)) +
+	       abs(int(m_green - colour.m_green)) +
+	       abs(int(m_blue - colour.m_blue)) < 32;
 }
 
 std::string serialise::default_context_to<obby::colour>::
