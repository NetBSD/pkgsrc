$NetBSD: patch-gtk_ScintillaGTK.cxx,v 1.1 2016/12/15 23:51:03 joerg Exp $

Pointers are not ordered relative to 0.

--- gtk/ScintillaGTK.cxx.orig	2016-12-13 21:23:33.721060803 +0000
+++ gtk/ScintillaGTK.cxx
@@ -1556,7 +1556,7 @@ void ScintillaGTK::ReceivedDrop(GtkSelec
 		drop.push_back('\0');
 		NotifyURIDropped(&drop[0]);
 	} else if ((TypeOfGSD(selection_data) == GDK_TARGET_STRING) || (TypeOfGSD(selection_data) == atomUTF8)) {
-		if (TypeOfGSD(selection_data) > 0) {
+		if (TypeOfGSD(selection_data)) {
 			SelectionText selText;
 			GetGtkSelectionText(selection_data, selText);
 			DropAt(posDrop, selText.Data(), selText.Length(), false, selText.rectangular);
