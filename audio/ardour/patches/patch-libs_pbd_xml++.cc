$NetBSD: patch-libs_pbd_xml++.cc,v 1.1 2024/02/10 10:41:43 wiz Exp $

Fix build with libxml2 2.12.

--- libs/pbd/xml++.cc.orig	2024-02-10 10:29:26.804670554 +0000
+++ libs/pbd/xml++.cc
@@ -168,7 +168,7 @@ XMLTree::write() const
 	result = xmlSaveFormatFileEnc(_filename.c_str(), doc, "UTF-8", 1);
 #ifndef NDEBUG
 	if (result == -1) {
-		xmlErrorPtr xerr = xmlGetLastError ();
+		const xmlError *xerr = xmlGetLastError ();
 		if (!xerr) {
 			std::cerr << "unknown XML error during xmlSaveFormatFileEnc()." << std::endl;
 		} else {
