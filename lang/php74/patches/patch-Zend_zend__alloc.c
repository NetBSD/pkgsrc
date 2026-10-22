$NetBSD: patch-Zend_zend__alloc.c,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_alloc.c.orig	2022-10-31 10:36:16.000000000 +0000
+++ Zend/zend_alloc.c
@@ -57,6 +57,7 @@
 #include "zend_operators.h"
 #include "zend_multiply.h"
 #include "zend_bitset.h"
+#include "zend_execute.h"
 #include <signal.h>
 
 #ifdef HAVE_UNISTD_H
@@ -363,7 +364,42 @@ static ZEND_COLD ZEND_NORETURN void zend
 #if ZEND_DEBUG && defined(HAVE_KILL) && defined(HAVE_GETPID)
 	kill(getpid(), SIGSEGV);
 #endif
-	exit(1);
+	_exit(1);
+}
+
+ZEND_API ZEND_COLD ZEND_NORETURN void zend_mm_safe_error_ex(const char *format, ...)
+{
+	zend_string *script_filename = NULL;
+	uint32_t script_lineno = 0;
+
+	if (zend_is_executing()) {
+		script_filename = zend_get_executed_filename_ex();
+		script_lineno = zend_get_executed_lineno();
+	} else if (zend_is_compiling()) {
+		script_filename = zend_get_compiled_filename();
+		script_lineno = zend_get_compiled_lineno();
+	}
+
+	va_list args;
+	va_start(args, format);
+
+	char buf[1024];
+	vsnprintf(buf, sizeof(buf), format, args);
+
+	va_end(args);
+
+	fprintf(stderr,
+			"\nFatal error: %s in %s on line %d\n",
+			buf,
+			script_filename ? ZSTR_VAL(script_filename) : "Unknown",
+			script_lineno);
+
+	/* See http://support.microsoft.com/kb/190351 */
+# ifdef ZEND_WIN32
+	fflush(stderr);
+# endif
+
+	_exit(1);
 }
 
 static ZEND_COLD ZEND_NORETURN void zend_mm_safe_error(zend_mm_heap *heap,
@@ -375,22 +411,14 @@ static ZEND_COLD ZEND_NORETURN void zend
 #endif
 	size_t size)
 {
+	(void) heap;
 
-	heap->overflow = 1;
-	zend_try {
-		zend_error_noreturn(E_ERROR,
-			format,
-			limit,
+	zend_mm_safe_error_ex(format, limit,
 #if ZEND_DEBUG
 			filename,
 			lineno,
 #endif
 			size);
-	} zend_catch {
-	}  zend_end_try();
-	heap->overflow = 0;
-	zend_bailout();
-	exit(1);
 }
 
 #ifdef _WIN32
@@ -1318,7 +1346,7 @@ static zend_always_inline void *zend_mm_
 	size = MAX(size, 1);
 	size = ZEND_MM_ALIGNED_SIZE(size) + ZEND_MM_ALIGNED_SIZE(sizeof(zend_mm_debug_info));
 	if (UNEXPECTED(size < real_size)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu + %zu)", ZEND_MM_ALIGNED_SIZE(real_size), ZEND_MM_ALIGNED_SIZE(sizeof(zend_mm_debug_info)));
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%zu + %zu)", ZEND_MM_ALIGNED_SIZE(real_size), ZEND_MM_ALIGNED_SIZE(sizeof(zend_mm_debug_info)));
 		return NULL;
 	}
 #endif
@@ -1762,7 +1790,7 @@ static void *zend_mm_alloc_huge(zend_mm_
 	void *ptr;
 
 	if (UNEXPECTED(new_size < size)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu + %zu)", size, alignment);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%zu + %zu)", size, alignment);
 	}
 
 #if ZEND_MM_LIMIT
@@ -2617,7 +2645,7 @@ ZEND_API char* ZEND_FASTCALL _estrdup(co
 
 	length = strlen(s);
 	if (UNEXPECTED(length + 1 == 0)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (1 * %zu + 1)", length);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (1 * %zu + 1)", length);
 	}
 	p = (char *) _emalloc(length + 1 ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
 	memcpy(p, s, length+1);
@@ -2629,7 +2657,7 @@ ZEND_API char* ZEND_FASTCALL _estrndup(c
 	char *p;
 
 	if (UNEXPECTED(length + 1 == 0)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (1 * %zu + 1)", length);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (1 * %zu + 1)", length);
 	}
 	p = (char *) _emalloc(length + 1 ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
 	memcpy(p, s, length);
@@ -2643,7 +2671,7 @@ ZEND_API char* ZEND_FASTCALL zend_strndu
 	char *p;
 
 	if (UNEXPECTED(length + 1 == 0)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (1 * %zu + 1)", length);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (1 * %zu + 1)", length);
 	}
 	p = (char *) malloc(length + 1);
 	if (UNEXPECTED(p == NULL)) {
@@ -2974,7 +3002,7 @@ ZEND_API zend_mm_heap *zend_mm_startup_e
 static ZEND_COLD ZEND_NORETURN void zend_out_of_memory(void)
 {
 	fprintf(stderr, "Out of memory\n");
-	exit(1);
+	_exit(1);
 }
 
 ZEND_API void * __zend_malloc(size_t len)
