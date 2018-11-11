$NetBSD: patch-etree.cc,v 1.1 2018/11/11 14:11:27 rhialto Exp $

Improve const-correctness.

--- etree.cc.orig	2004-05-29 23:00:05.000000000 +0000
+++ etree.cc
@@ -79,7 +79,7 @@ pred<ClassType> *new_comparison(RetType 
 	return new Comparison<Op, MemGetter, RetType, ClassType>(member, v);
 }
 template <template <class A, class B> class Op, class ClassType, class RetType>
-pred<ClassType> *new_comparison(RetType (ClassType::*memberf)(void), RetType v){
+pred<ClassType> *new_comparison(RetType (ClassType::*memberf)(void) const, RetType v){
 	return new Comparison<Op, MemfuncGetter, RetType, ClassType>(memberf, v);
 }
 template <class ClassType, class getterT, class T2>
@@ -112,7 +112,7 @@ pred<ClassType> *new_comparison_re(RetTy
 	return new Comparison_re<Op, MemGetter, RetType, ClassType>(member, pattern, flags);
 }
 template <template <class A, class B> class Op, class ClassType, class RetType>
-pred<ClassType> *new_comparison_re(RetType (ClassType::*memberf)(void), const char *pattern, int flags){
+pred<ClassType> *new_comparison_re(RetType (ClassType::*memberf)(void) const, const char *pattern, int flags){
 	return new Comparison_re<Op, MemfuncGetter, RetType, ClassType>(memberf, pattern, flags);
 }
 template <class ClassType, class getterT>
