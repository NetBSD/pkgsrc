$NetBSD: patch-src_CLucene_index_SegmentMerger.cpp,v 1.1 2012/11/16 01:07:27 joerg Exp $

--- src/CLucene/index/SegmentMerger.cpp.orig	2012-11-13 16:35:06.000000000 +0000
+++ src/CLucene/index/SegmentMerger.cpp
@@ -249,7 +249,7 @@ int32_t SegmentMerger::mergeFields() {
     CND_CONDITION(fieldsWriter != NULL,"Memory allocation for fieldsWriter failed");
 
     try {  
-        IndexReader* reader = NULL;
+        reader = NULL;
 		int32_t maxDoc          = 0;
         //Iterate through all readers
         for (uint32_t i = 0; i < readers.size(); i++) {
