$NetBSD: patch-Zend_zend__llist.c,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_llist.c.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_llist.c
@@ -112,6 +112,8 @@ ZEND_API void zend_llist_destroy(zend_ll
 		current = next;
 	}
 
+	l->head  = NULL;
+	l->tail  = NULL;
 	l->count = 0;
 }
 
