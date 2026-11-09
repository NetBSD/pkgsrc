$NetBSD: patch-Zend_zend__llist.c,v 1.1.2.2 2026/11/09 08:24:26 maya Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- Zend/zend_llist.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend_llist.c
@@ -115,6 +115,8 @@ ZEND_API void zend_llist_destroy(zend_ll
 		current = next;
 	}
 
+	l->head  = NULL;
+	l->tail  = NULL;
 	l->count = 0;
 }
 
