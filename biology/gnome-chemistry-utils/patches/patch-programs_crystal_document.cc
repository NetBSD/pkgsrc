$NetBSD: patch-programs_crystal_document.cc,v 1.1 2013/05/09 13:45:45 joerg Exp $

--- programs/crystal/document.cc.orig	2013-05-07 20:13:58.000000000 +0000
+++ programs/crystal/document.cc
@@ -607,7 +607,7 @@ void gcDocument::OnExportVRML (const str
 		if (error) {
 			cerr << "gio error: " << error->message << endl;
 			g_error_free (error);
-			g_object_unref (file);
+			g_object_unref (stream);
 			throw (int) 1;
 		}
 		std::map<std::string, sAtom>AtomsMap;
