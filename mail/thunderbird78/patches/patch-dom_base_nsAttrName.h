$NetBSD: patch-dom_base_nsAttrName.h,v 1.1 2023/02/05 08:32:24 he Exp $

--- dom/base/nsAttrName.h.orig	2020-08-28 21:32:30.000000000 +0000
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
