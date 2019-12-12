$NetBSD: patch-tests_channel-class-spec.cpp,v 1.1 2019/12/12 16:44:53 nros Exp $
* remove use of deprecated function
--- tests/channel-class-spec.cpp.orig	2019-12-10 09:48:42.267292950 +0000
+++ tests/channel-class-spec.cpp
@@ -13,7 +13,7 @@ ChannelClassSpecList reverse(const Chann
 {
     ChannelClassSpecList ret(list);
     for (int k = 0; k < (list.size() / 2); k++) {
-        ret.swap(k, list.size() - (1 + k));
+        ret.swapItemsAt(k, list.size() - (1 + k));
     }
     return ret;
 }
