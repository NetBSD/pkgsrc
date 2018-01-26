$NetBSD: patch-src_core_CLucene_queryParser_QueryParserTokenManager.h,v 1.1 2018/01/26 15:27:04 jperkin Exp $

Fix -Wc++11-narrowing.

--- src/core/CLucene/queryParser/QueryParserTokenManager.h.orig	2011-03-17 00:21:07.000000000 +0000
+++ src/core/CLucene/queryParser/QueryParserTokenManager.h
@@ -35,8 +35,8 @@ private:
 	void jjCheckNAddStates(int32_t start, const int32_t end);
 	void jjCheckNAddStates(const int32_t start);
 
-	static const int64_t jjbitVec0[];
-	static const int64_t jjbitVec2[];
+	static const uint64_t jjbitVec0[];
+	static const uint64_t jjbitVec2[];
 
 	int32_t jjMoveNfa_3(const int32_t startState, int32_t curPos);
 
