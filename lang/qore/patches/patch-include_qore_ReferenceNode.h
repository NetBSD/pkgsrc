$NetBSD: patch-include_qore_ReferenceNode.h,v 1.1 2016/12/17 23:30:12 joerg Exp $

Friend relationship is not inherited, so be explicit where it is needed.

--- include/qore/ReferenceNode.h.orig	2016-12-17 21:43:24.075336551 +0000
+++ include/qore/ReferenceNode.h
@@ -45,6 +45,7 @@
 class ReferenceNode : public AbstractQoreNode {
    friend class RuntimeReferenceHelper;
    friend class lvalue_ref;
+   template <class T> friend class LValueRefHelper;
 
 private:
    //! private implementation
