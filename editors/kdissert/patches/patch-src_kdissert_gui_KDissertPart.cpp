$NetBSD: patch-src_kdissert_gui_KDissertPart.cpp,v 1.1 2013/05/11 21:36:56 joerg Exp $

--- src/kdissert/gui/KDissertPart.cpp.orig	2013-05-10 15:12:25.000000000 +0000
+++ src/kdissert/gui/KDissertPart.cpp
@@ -482,10 +482,11 @@ void KDissertPart::regenerateDocument()
 
 	// read last generation date (for backup suffix) and save the actual one
 	std::string hash;
-	std::ifstream is(m_data->m_generator_lasturl+"/.kdissert");
+	
+	std::ifstream is((m_data->m_generator_lasturl+"/.kdissert").ascii());
 	is>>hash;
 	is.close();
-	std::ofstream os(m_data->m_generator_lasturl+"/.kdissert");
+	std::ofstream os((m_data->m_generator_lasturl+"/.kdissert").ascii());
 	os<<QDate::currentDate().toString(Qt::ISODate)
 		<<'-'
 		<<QTime::currentTime().toString(Qt::ISODate);
