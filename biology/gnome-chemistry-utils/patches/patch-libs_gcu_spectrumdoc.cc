$NetBSD: patch-libs_gcu_spectrumdoc.cc,v 1.1 2013/05/09 13:45:45 joerg Exp $

--- libs/gcu/spectrumdoc.cc.orig	2013-05-07 20:06:58.000000000 +0000
+++ libs/gcu/spectrumdoc.cc
@@ -1618,7 +1618,7 @@ void SpectrumDocument::ReadDataTable (is
 			break;	// this should not occur, but a corrupted or bad file is always possible
 		s.getline (line, 300);
 		if (strstr (line, "##")) {
-			s.seekg (-strlen (line) -1, _S_cur);
+			s.seekg (-strlen (line) -1, ios::cur);
 			if (read > npoints) {
 				g_warning (_("Found too many data!"));
 				// FIXME: throw an exception
