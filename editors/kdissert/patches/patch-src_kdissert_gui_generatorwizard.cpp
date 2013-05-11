$NetBSD: patch-src_kdissert_gui_generatorwizard.cpp,v 1.1 2013/05/11 21:36:56 joerg Exp $

--- src/kdissert/gui/generatorwizard.cpp.orig	2013-05-10 15:14:38.000000000 +0000
+++ src/kdissert/gui/generatorwizard.cpp
@@ -139,10 +139,10 @@ void generatorwizard::accept()
 
 	// read last generation date (for backup suffix) and save the actual one
 	std::string hash("ERROR"); // if hash is used for backup, but not read from file, it's an error
-	std::ifstream is(m_data->m_generator_lasturl+"/.kdissert");
+	std::ifstream is((m_data->m_generator_lasturl+"/.kdissert").ascii());
 	is>>hash;
 	is.close();
-	std::ofstream os(m_page1->docfinallocation->text()+"/.kdissert");
+	std::ofstream os((m_page1->docfinallocation->text()+"/.kdissert").ascii());
 	os<<QDate::currentDate().toString(Qt::ISODate)
 		<<'-'
 		<<QTime::currentTime().toString(Qt::ISODate);
