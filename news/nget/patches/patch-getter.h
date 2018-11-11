$NetBSD: patch-getter.h,v 1.1 2018/11/11 14:11:27 rhialto Exp $

Improve const-correctness.

--- getter.h.orig	2018-04-16 19:54:17.000000000 +0000
+++ getter.h
@@ -35,7 +35,7 @@ class MemGetter {
 template <class RetType, class ClassType>
 class MemfuncGetter {
 	private:
-		typedef RetType (ClassType::*member_t)(void);
+		typedef RetType (ClassType::*member_t)(void) const;
 		member_t member;		
 	public:
 		typedef RetType T;
