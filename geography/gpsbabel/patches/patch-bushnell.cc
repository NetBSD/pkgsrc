$NetBSD: patch-bushnell.cc,v 1.1 2016/12/21 13:37:24 joerg Exp $

Don't check pointer signs.

--- bushnell.cc.orig	2016-12-21 00:00:02.839899031 +0000
+++ bushnell.cc
@@ -135,7 +135,7 @@ bushnell_get_icon_from_name(QString name
     name = "Waypoint";
   }
 
-  for (t = bushnell_icons; t->icon > 0; t++) {
+  for (t = bushnell_icons; t->icon; t++) {
     if (0 == name.compare(t->icon, Qt::CaseInsensitive)) {
       return t->symbol;
     }
@@ -147,7 +147,7 @@ static const char*
 bushnell_get_name_from_symbol(signed int s)
 {
   icon_mapping_t* t;
-  for (t = bushnell_icons; t->icon > 0; t++) {
+  for (t = bushnell_icons; t->icon; t++) {
     if (s == t->symbol) {
       return t->icon;
     }
