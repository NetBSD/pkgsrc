$NetBSD: patch-include_qore_intern_QoreLValue.h,v 1.1 2020/03/19 23:59:58 joerg Exp $

Can't modify member variables from a const method.

--- include/qore/intern/QoreLValue.h.orig	2020-03-18 20:41:49.184549910 +0000
+++ include/qore/intern/QoreLValue.h
@@ -1022,7 +1022,7 @@ public:
       return "NOTHING";
    }
 
-   DLLLOCAL AbstractQoreNode** getValuePtr(ExceptionSink* xsink) const {
+   DLLLOCAL AbstractQoreNode** getValuePtr(ExceptionSink* xsink) {
       if (!fixed_type) {
          if (type != QV_Node)
             type = QV_Node;
