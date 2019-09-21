$NetBSD: patch-dom_base_nsAttrName.h,v 1.1 2019/09/21 10:55:17 ryoon Exp $

--- dom/base/nsAttrName.h.orig	2019-09-09 23:43:25.000000000 +0000
+++ dom/base/nsAttrName.h
@@ -16,6 +16,10 @@
 #include "mozilla/dom/NodeInfo.h"
 #include "nsAtom.h"
 #include "nsDOMString.h"
+#ifdef __NetBSD__
+/* This is also a macro which causes problems with cbindgen */
+#undef uintptr_t
+#endif
 
 #define NS_ATTRNAME_NODEINFO_BIT 1
 class nsAttrName {
