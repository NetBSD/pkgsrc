$NetBSD: patch-Zend_zend__vm__def.h,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_vm_def.h.orig	2022-10-31 10:36:14.000000000 +0000
+++ Zend/zend_vm_def.h
@@ -417,7 +417,7 @@ ZEND_VM_HANDLER(8, ZEND_CONCAT, CONST|TM
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -426,6 +426,9 @@ ZEND_VM_HANDLER(8, ZEND_CONCAT, CONST|TM
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -3210,6 +3213,9 @@ ZEND_VM_COLD_CONSTCONST_HANDLER(53, ZEND
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -3217,6 +3223,9 @@ ZEND_VM_COLD_CONSTCONST_HANDLER(53, ZEND
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
