$NetBSD: patch-src_dict_table.cc,v 1.1 2015/04/14 14:38:05 joerg Exp $

--- src/dict/table.cc.orig	2013-11-10 10:20:21.000000000 +0000
+++ src/dict/table.cc
@@ -403,14 +403,15 @@ bool Table::BuildEntryList(const DictEnt
   return true;
 }
 
-bool Table::BuildEntry(const DictEntry &dict_entry, table::Entry *entry) {
+bool Table::BuildEntry(const DictEntry &dict_entry, __attribute__((aligned(1))) table::Entry *entry) {
   if (!entry)
     return false;
   if (!CopyString(dict_entry.text, &entry->text)) {
     LOG(ERROR) << "Error creating table entry '" << dict_entry.text << "'; file size: " << file_size();
     return false;
   }
-  entry->weight = static_cast<float>(dict_entry.weight);
+  float weight = static_cast<float>(dict_entry.weight);
+  memcpy(&entry->weight, &weight, sizeof(weight));
   return true;
 }
 
