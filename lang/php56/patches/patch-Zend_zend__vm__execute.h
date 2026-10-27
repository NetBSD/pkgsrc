$NetBSD: patch-Zend_zend__vm__execute.h,v 1.1 2026/10/27 15:30:49 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- Zend/zend_vm_execute.h.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend_vm_execute.h
@@ -359,6 +359,10 @@ zend_vm_enter:
 			zend_timeout(0);
 		}
 #endif
+		/* Safe point: no opcode is being executed */
+		if (ZEND_OOM_PENDING()) {
+			zend_handle_delayed_oom(TSRMLS_C);
+		}
 
 		if ((ret = OPLINE->handler(execute_data TSRMLS_CC)) > 0) {
 			switch (ret) {
