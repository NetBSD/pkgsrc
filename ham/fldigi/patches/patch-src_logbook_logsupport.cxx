$NetBSD: patch-src_logbook_logsupport.cxx,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/logbook/logsupport.cxx.orig	2013-05-03 14:19:39.000000000 +0000
+++ src/logbook/logsupport.cxx
@@ -211,7 +211,7 @@ void Export_ADIF()
 		}
 	}
 	string sp = p;
-	if (sp.find("."ADIF_SUFFIX) == string::npos) sp.append("."ADIF_SUFFIX);
+	if (sp.find("." ADIF_SUFFIX) == string::npos) sp.append("." ADIF_SUFFIX);
 	adifFile.writeFile (sp.c_str(), &qsodb);
 }
 
@@ -308,8 +308,8 @@ void cb_mnuSaveLogbook(Fl_Menu_*m, void*
 	const char* p = FSEL::saveas( title.c_str(), filter.c_str(), logbook_filename.c_str());
 	if (p) {
 		logbook_filename = p;
-		if (logbook_filename.find("."ADIF_SUFFIX) == string::npos)
-			logbook_filename.append("."ADIF_SUFFIX);
+		if (logbook_filename.find("." ADIF_SUFFIX) == string::npos)
+			logbook_filename.append("." ADIF_SUFFIX);
 		dlgLogbook->label(fl_filename_name(logbook_filename.c_str()));
 
 		cQsoDb::reverse = false;
@@ -1542,9 +1542,13 @@ SOAPBOX: \n\n",
     return;
 }
 
-
+#if __cplusplus >= 200103L
+#include <unordered_map>
+typedef unordered_map<string, unsigned> dxcc_entity_cache_t;
+#else
 #include <tr1/unordered_map>
 typedef tr1::unordered_map<string, unsigned> dxcc_entity_cache_t;
+#endif
 static dxcc_entity_cache_t dxcc_entity_cache;
 static bool dxcc_entity_cache_enabled = false;
 
