$NetBSD: patch-src_dict_table.cc,v 1.2 2015/04/21 13:59:31 hiramatsu Exp $

Entries in the output file are generally not correctly aligned,
so tell the compiler explicitly about this fact and use memcpy
for writing the data.

--- src/dict/table.cc.orig	2013-11-10 19:20:21.000000000 +0900
+++ src/dict/table.cc	2015-04-18 12:14:33.000000000 +0900
@@ -403,14 +403,15 @@
   return true;
 }
 
-bool Table::BuildEntry(const DictEntry &dict_entry, table::Entry *entry) {
+bool Table::BuildEntry(const DictEntry &dict_entry, table::Entry * __attribute__((aligned(1))) entry) {
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
 
