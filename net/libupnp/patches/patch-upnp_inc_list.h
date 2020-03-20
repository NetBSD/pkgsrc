$NetBSD: patch-upnp_inc_list.h,v 1.1 2020/03/20 20:46:40 joerg Exp $

Stop messing with standard symbols.

--- upnp/inc/list.h.orig	2020-03-20 19:21:31.152627060 +0000
+++ upnp/inc/list.h
@@ -22,9 +22,6 @@
 
 #include "UpnpGlobal.h" /* For UPNP_INLINE */
 
-#define bool int
-#define true !0
-
 #undef READ_ONCE
 #define READ_ONCE(x) x
 
@@ -79,21 +76,21 @@ static UPNP_INLINE void INIT_LIST_HEAD(s
 }
 
 #ifdef CONFIG_DEBUG_LIST
-extern bool __list_add_valid(struct list_head *newent,
+extern int __list_add_valid(struct list_head *newent,
 			      struct list_head *prev,
 			      struct list_head *next);
-extern bool __list_del_entry_valid(struct list_head *entry);
+extern int __list_del_entry_valid(struct list_head *entry);
 #else
-static UPNP_INLINE bool __list_add_valid(struct list_head *newent,
+static UPNP_INLINE int __list_add_valid(struct list_head *newent,
 				struct list_head *prev,
 				struct list_head *next)
 {
-	return true;
+	return !0;
 	newent++; prev++; next++; /* against compiler warnings */
 }
-static UPNP_INLINE bool __list_del_entry_valid(struct list_head *entry)
+static UPNP_INLINE int __list_del_entry_valid(struct list_head *entry)
 {
-	return true;
+	return !0;
 	entry++; /* against compiler warnings */
 }
 #endif
@@ -754,7 +751,7 @@ static UPNP_INLINE void hlist_add_fake(s
 	n->pprev = &n->next;
 }
 
-static UPNP_INLINE bool hlist_fake(struct hlist_node *h)
+static UPNP_INLINE int hlist_fake(struct hlist_node *h)
 {
 	return h->pprev == &h->next;
 }
@@ -763,7 +760,7 @@ static UPNP_INLINE bool hlist_fake(struc
  * Check whether the node is the only node of the head without
  * accessing head:
  */
-static UPNP_INLINE bool
+static UPNP_INLINE int
 hlist_is_singular_node(struct hlist_node *n, struct hlist_head *h)
 {
 	return !n->next && n->pprev == &h->first;
@@ -838,6 +835,4 @@ static UPNP_INLINE void hlist_move_list(
 	     pos && ({ n = pos->member.next; 1; });			\
 	     pos = hlist_entry_safe(n, typeof(*pos), member))
 
-#undef bool
-#undef true
 #endif
