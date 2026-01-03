$NetBSD: patch-src_web_config__load.cc,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/web/config_load.cc.orig	2026-01-03 10:22:29.869812021 +0000
+++ src/web/config_load.cc
@@ -114,7 +114,7 @@ void Web::ConfigLoad::createItem(pugi::x
 template <typename T>
 void Web::ConfigLoad::setValue(pugi::xml_node& item, const T& value)
 {
-    static_assert(fmt::has_formatter<T, fmt::format_context>::value, "T must be formattable");
+    static_assert(fmt::is_formattable<T, fmt::format_context>::value, "T must be formattable");
     item.append_attribute(CONFIG_LOAD_VALUE) = fmt::to_string(value).c_str();
 }
 
@@ -917,7 +917,7 @@ void Web::ConfigLoad::writeAutoscan(pugi
             // Last modified
             item = values.append_child(CONFIG_LOAD_ITEM);
             createItem(item, ascs->getItemPath(indexList, { ConfigVal::A_AUTOSCAN_DIRECTORY_LMT }), ascs->option, ConfigVal::A_AUTOSCAN_DIRECTORY_LMT);
-            setValue(item, fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(adir->getPreviousLMT().count())));
+            setValue(item, grbLocaltime("{:%Y-%m-%d %H:%M:%S}", adir->getPreviousLMT()));
         }
         // Allow creation of entry in blank config
         {
