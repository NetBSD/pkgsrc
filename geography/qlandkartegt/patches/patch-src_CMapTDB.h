$NetBSD: patch-src_CMapTDB.h,v 1.1 2013/05/23 15:03:51 joerg Exp $

--- src/CMapTDB.h.orig	2013-05-23 14:26:27.000000000 +0000
+++ src/CMapTDB.h
@@ -210,7 +210,7 @@ class CMapTDB : public IMap
             quint8 level;
             bool useBaseMap;
 
-            bool operator==(const map_level_t &ml)
+            bool operator==(const map_level_t &ml) const
             {
                 if (ml.bits != bits || ml.level != level || ml.useBaseMap != useBaseMap)
                     return false;
