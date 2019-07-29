$NetBSD: patch-Source_list.h,v 1.1 2019/07/29 09:34:32 nia Exp $

[PATCH] Cast pointer to ptrdiff_t to make code less undefined for 64-bit.
https://github.com/diasurgical/devilutionX/commit/c4c2132ac67a457cc7f55cc8a6d5e099747dbdb8.patch

--- Source/list.h.orig	2019-05-19 17:06:45.000000000 +0000
+++ Source/list.h
@@ -196,17 +196,17 @@ public:
 
 	T *Next()
 	{
-		if ((intptr_t)m_nextNode <= 0)
+		if ((ptrdiff_t)m_nextNode <= 0)
 			return NULL;
 		return m_nextNode;
 	}
 
 	TLink<T> *NextLink(size_t offset = -1)
 	{
-		if ((intptr_t)m_nextNode <= 0)
+		if ((ptrdiff_t)m_nextNode <= 0)
 			return (TLink<T> *)~((size_t)m_nextNode);
 
-		if ((intptr_t)offset < 0) {
+		if ((int)offset < 0) {
 			// Calculate the offset from a node pointer to a link structure
 			offset = (size_t)this - (size_t)m_prevLink->m_nextNode;
 		}
