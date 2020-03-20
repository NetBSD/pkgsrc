$NetBSD: patch-testddl.cpp,v 1.1 2020/03/20 20:45:46 joerg Exp $

--- testddl.cpp.orig	2020-03-20 18:59:33.126845571 +0000
+++ testddl.cpp
@@ -102,8 +102,8 @@ class Record : public Base {
 
 REGISTER(Record);
 
-USER_FUNC(sin);
-USER_FUNC(cos);
+USER_FUNC2(sin, (real8(*)(real8))(cos));
+USER_FUNC2(cos, (real8(*)(real8))(sin));
 
 int __cdecl main()
 {
