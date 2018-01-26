$NetBSD: patch-src_core_CLucene_queryParser_QueryParserTokenManager.cpp,v 1.1 2018/01/26 15:27:04 jperkin Exp $

Fix -Wc++11-narrowing.

--- src/core/CLucene/queryParser/QueryParserTokenManager.cpp.orig	2011-03-17 00:21:07.000000000 +0000
+++ src/core/CLucene/queryParser/QueryParserTokenManager.cpp
@@ -15,8 +15,8 @@
 
 CL_NS_DEF(queryParser)
 
-const int64_t QueryParserTokenManager::jjbitVec2[]={0x0L, 0x0L, _ILONGLONG(0xffffffffffffffff), _ILONGLONG(0xffffffffffffffff)};
-const int64_t QueryParserTokenManager::jjbitVec0[] = {
+const uint64_t QueryParserTokenManager::jjbitVec2[]={0x0L, 0x0L, _ILONGLONG(0xffffffffffffffff), _ILONGLONG(0xffffffffffffffff)};
+const uint64_t QueryParserTokenManager::jjbitVec0[] = {
 	_ILONGLONG(0xfffffffffffffffe), _ILONGLONG(0xffffffffffffffff), _ILONGLONG(0xffffffffffffffff), _ILONGLONG(0xffffffffffffffff)
 };
 const int32_t QueryParserTokenManager::jjnextStates[]={
