$NetBSD: patch-Zend_zend__alloc.h,v 1.1 2026/10/27 15:30:48 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- Zend/zend_alloc.h.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend_alloc.h
@@ -50,6 +50,25 @@ typedef struct _zend_leak_info {
 	uint orig_lineno;
 } zend_leak_info;
 
+/* Delayed out of memory handling (CVE-2026-109618).
+ *
+ * Exceeding memory_limit no longer bails out (longjmp) from inside the
+ * allocator, where the caller may have left request memory in an
+ * inconsistent state. Instead the allocation succeeds, the error is recorded
+ * and raised as a fatal error at the next safe point (between two opcodes, or
+ * once request startup has finished parsing the request). Memory usage beyond
+ * a hard limit (twice memory_limit, or memory_limit + 1G for limits above 1G)
+ * terminates the process immediately with _exit(). */
+typedef enum _zend_oom_state {
+	ZEND_OOM_STATE_NONE = 0,
+	ZEND_OOM_STATE_PENDING,
+	ZEND_OOM_STATE_HANDLING,
+	ZEND_OOM_STATE_HANDLED
+} zend_oom_state;
+
+#define ZEND_HAS_OOM() (UNEXPECTED(EG(delayed_oom) != ZEND_OOM_STATE_NONE))
+#define ZEND_OOM_PENDING() (UNEXPECTED(EG(delayed_oom) == ZEND_OOM_STATE_PENDING))
+
 BEGIN_EXTERN_C()
 
 ZEND_API char *zend_strndup(const char *s, unsigned int length) ZEND_ATTRIBUTE_MALLOC;
@@ -142,6 +161,7 @@ inline static void * __zend_realloc(void
 #define safe_estrndup(ptr, len) ((ptr)?(estrndup((ptr), (len))):STR_EMPTY_ALLOC())
 
 ZEND_API int zend_set_memory_limit(size_t memory_limit);
+ZEND_API void zend_handle_delayed_oom(TSRMLS_D);
 
 ZEND_API void start_memory_manager(TSRMLS_D);
 ZEND_API void shutdown_memory_manager(int silent, int full_shutdown TSRMLS_DC);
