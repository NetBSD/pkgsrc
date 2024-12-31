$NetBSD: patch-src_core_hook_hook-url.h,v 1.1 2024/12/31 15:57:36 ryoon Exp $

* For pthread_t.

--- src/core/hook/hook-url.h.orig	2024-12-31 14:30:06.517512750 +0000
+++ src/core/hook/hook-url.h
@@ -20,6 +20,8 @@
 #ifndef WEECHAT_HOOK_URL_H
 #define WEECHAT_HOOK_URL_H
 
+#include <pthread.h>
+
 struct t_weechat_plugin;
 struct t_infolist_item;
 struct t_hashtable;
