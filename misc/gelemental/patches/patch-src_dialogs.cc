$NetBSD: patch-src_dialogs.cc,v 1.1 2015/10/20 09:40:22 tnn Exp $

dialogs.cc:250:14: error: incompatible operand types
      ('Elemental::PropertyBase *' and 'bool')
        return iter ? iter->get_value (cols.property) : false;

(not sure if this is in line with what the code intends)

--- src/dialogs.cc.orig	2007-09-25 04:49:33.000000000 +0000
+++ src/dialogs.cc
@@ -247,7 +247,7 @@ PropertiesDialog::is_selectable (const R
 	const Gtk::TreePath& tpath, bool)
 {
 	Gtk::TreeIter iter = store->get_iter (tpath);
-	return iter ? iter->get_value (cols.property) : false;
+	return iter ? (iter->get_value (cols.property) != NULL) : false;
 }
 
 
