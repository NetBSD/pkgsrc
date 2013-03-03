$NetBSD: patch-ext_scintilla_gtk_ScintillaGTK.cxx,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- ext/scintilla/gtk/ScintillaGTK.cxx.orig	2013-02-28 22:22:41.000000000 +0000
+++ ext/scintilla/gtk/ScintillaGTK.cxx
@@ -1297,7 +1297,7 @@ void ScintillaGTK::AddToPopUp(const char
 	GtkItemFactoryEntry itemEntry = {
 	    fulllabel, NULL,
 	    menuSig,
-	    cmd,
+	    static_cast<guint>(cmd),
 	    const_cast<gchar *>(label[0] ? "<Item>" : "<Separator>"),
 	    NULL
 	};
