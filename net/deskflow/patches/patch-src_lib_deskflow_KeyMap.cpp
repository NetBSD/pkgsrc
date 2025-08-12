$NetBSD: patch-src_lib_deskflow_KeyMap.cpp,v 1.1 2025/08/12 17:05:11 tnn Exp $

Work around issue with Swedish keymap in client.
https://github.com/deskflow/deskflow/issues/8839

--- src/lib/deskflow/KeyMap.cpp.orig	2025-08-12 16:55:42.844426038 +0000
+++ src/lib/deskflow/KeyMap.cpp
@@ -211,14 +211,14 @@ void KeyMap::finish()
 
 void KeyMap::foreachKey(ForeachKeyCallback cb, void *userData)
 {
-  for (const auto &[keyId, keyGroup] : m_keyIDMap) {
-    const KeyGroupTable &groupTable = keyGroup;
+  for (auto i = m_keyIDMap.begin(); i != m_keyIDMap.end(); ++i) {
+    KeyGroupTable &groupTable = i->second;
     for (size_t group = 0; group < groupTable.size(); ++group) {
-      const KeyEntryList &entryList = groupTable.at(group);
-      for (auto &entry : entryList) {
-        const KeyItemList &itemList = entry;
-        for (auto item : itemList) {
-          (*cb)(keyId, static_cast<int32_t>(group), item, userData);
+      KeyEntryList &entryList = groupTable[group];
+      for (size_t j = 0; j < entryList.size(); ++j) {
+        KeyItemList &itemList = entryList[j];
+        for (size_t k = 0; k < itemList.size(); ++k) {
+          (*cb)(i->first, static_cast<int32_t>(group), itemList[k], userData);
         }
       }
     }
