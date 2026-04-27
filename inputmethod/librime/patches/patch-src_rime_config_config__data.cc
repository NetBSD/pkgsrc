$NetBSD: patch-src_rime_config_config__data.cc,v 1.1 2026/04/27 10:52:42 wiz Exp $

Fix ctype(3) API abuse.

--- src/rime/config/config_data.cc.orig	2026-04-27 10:48:42.262818340 +0000
+++ src/rime/config/config_data.cc
@@ -96,7 +96,7 @@ bool ConfigData::IsListItemReference(const string& key
 }
 
 bool ConfigData::IsListItemReference(const string& key) {
-  return key.length() > 1 && key[0] == '@' && std::isalnum(key[1]);
+  return key.length() > 1 && key[0] == '@' && std::isalnum((unsigned char)key[1]);
 }
 
 string ConfigData::FormatListIndex(size_t index) {
@@ -293,7 +293,7 @@ void EmitScalar(const string& str_value, YAML::Emitter
   if (str_value.find_first_of("\r\n") != string::npos) {
     *emitter << YAML::Literal;
   } else if (!std::all_of(str_value.cbegin(), str_value.cend(), [](auto ch) {
-               return std::isalnum(ch) || ch == '_' || ch == '.';
+               return std::isalnum((unsigned char)ch) || ch == '_' || ch == '.';
              })) {
     *emitter << YAML::DoubleQuoted;
   }
