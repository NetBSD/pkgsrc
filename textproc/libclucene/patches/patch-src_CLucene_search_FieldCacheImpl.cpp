$NetBSD: patch-src_CLucene_search_FieldCacheImpl.cpp,v 1.1 2012/11/16 01:07:27 joerg Exp $

--- src/CLucene/search/FieldCacheImpl.cpp.orig	2012-11-13 16:37:37.000000000 +0000
+++ src/CLucene/search/FieldCacheImpl.cpp
@@ -414,7 +414,7 @@ FieldCacheImpl::FileEntry::FileEntry (co
 	  _CLDECDELETE(term);
 
       try {
-        Term* term = enumerator->term(false);
+        term = enumerator->term(false);
         if (term == NULL) {
           _CLTHROWA(CL_ERR_Runtime,"no terms in field - cannot determine sort type"); //todo: make rich error: " + field + " 
         }
