$NetBSD: patch-comphelper_inc_comphelper_InlineContainer.hxx,v 1.1 2013/04/01 12:19:13 joerg Exp $

--- comphelper/inc/comphelper/InlineContainer.hxx.orig	2013-03-30 19:59:55.000000000 +0000
+++ comphelper/inc/comphelper/InlineContainer.hxx
@@ -102,7 +102,7 @@ public:
     explicit MakeSet(const T &a)
         : ::std::set< T >()
     {
-        insert(this->end(), a);
+        this->insert(this->end(), a);
     }
     MakeSet &operator()(const T &a)
     {
