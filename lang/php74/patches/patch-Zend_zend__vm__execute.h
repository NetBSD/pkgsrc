$NetBSD: patch-Zend_zend__vm__execute.h,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_vm_execute.h.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_vm_execute.h
@@ -5631,6 +5631,9 @@ static ZEND_VM_COLD ZEND_OPCODE_HANDLER_
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -5638,6 +5641,9 @@ static ZEND_VM_COLD ZEND_OPCODE_HANDLER_
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -7491,6 +7497,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -7498,6 +7507,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -7900,7 +7912,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -7909,6 +7921,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -9952,6 +9967,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -9959,6 +9977,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -10361,7 +10382,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -10370,6 +10391,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -13928,6 +13952,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -13935,6 +13962,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -14681,7 +14711,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -14690,6 +14720,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -15353,7 +15386,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -15362,6 +15395,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -16107,6 +16143,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -16114,6 +16153,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -17040,7 +17082,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -17049,6 +17091,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -17401,6 +17446,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -17408,6 +17456,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -38348,7 +38399,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -38357,6 +38408,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -40727,7 +40781,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -40736,6 +40790,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -41849,6 +41906,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -41856,6 +41916,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -44132,6 +44195,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -44139,6 +44205,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -46857,7 +46926,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -46866,6 +46935,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -49268,6 +49340,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -49275,6 +49350,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
