$NetBSD: patch-gio_giomm_dbussubtreevtable.cc,v 1.1 2012/11/16 00:45:25 joerg Exp $

--- gio/giomm/dbussubtreevtable.cc.orig	2012-11-13 21:31:09.000000000 +0000
+++ gio/giomm/dbussubtreevtable.cc
@@ -122,13 +122,13 @@ static const GDBusInterfaceVTable* DBusS
 
   try
   {
-    const Gio::DBus::InterfaceVTable* vtable =
+    const Gio::DBus::InterfaceVTable* vtable2 =
       (*the_slot)(Glib::wrap(connection, true), sender, object_path,
       interface_name, (node ? node : ""));
 
-    *out_user_data = const_cast<Gio::DBus::InterfaceVTable*>(vtable);
+    *out_user_data = const_cast<Gio::DBus::InterfaceVTable*>(vtable2);
 
-    return vtable->gobj();
+    return vtable2->gobj();
   }
   catch(...)
   {
