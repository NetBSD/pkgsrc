$NetBSD: patch-Zend_zend__alloc.c,v 1.1 2026/10/27 15:30:48 taca Exp $

https://raw.githubusercontent.com/Anton-Barinov/php2shell-patches/refs/heads/main/patches/php-5.6-enhanced-universal.patch

--- Zend/zend_alloc.c.orig	2019-01-09 09:54:13.000000000 +0000
+++ Zend/zend_alloc.c
@@ -426,12 +426,17 @@ struct _zend_mm_heap {
 	size_t              real_size;
 	size_t              real_peak;
 	size_t              limit;
+	size_t              hard_limit;             /* see zend_mm_update_hard_limit() */
 	size_t              size;
 	size_t              peak;
 	size_t              reserve_size;
 	void               *reserve;
 	int                 overflow;
 	int                 internal;
+	/* Delayed OOM error, raised by zend_handle_delayed_oom() */
+	uint                oom_lineno;
+	char                oom_filename[1024];
+	char                oom_message[1024];
 #if ZEND_MM_CACHE
 	unsigned int        cached;
 	zend_mm_free_block *cache[ZEND_MM_NUM_BUCKETS];
@@ -1117,6 +1122,7 @@ ZEND_API zend_mm_heap *zend_mm_startup_e
 	heap->overflow = 0;
 	heap->real_peak = 0;
 	heap->limit = ZEND_MM_LONG_CONST(1)<<(ZEND_MM_NUM_BUCKETS-2);
+	heap->hard_limit = heap->limit;
 	heap->size = 0;
 	heap->peak = 0;
 	heap->internal = internal;
@@ -1598,6 +1604,27 @@ static int zend_mm_check_heap(zend_mm_he
 }
 #endif
 
+/* The hard limit leaves room above memory_limit for the request to reach the
+ * next safe point: 200% of memory_limit, or memory_limit + 1G above 1G. */
+static void zend_mm_update_hard_limit(zend_mm_heap *heap)
+{
+	size_t headroom = MIN(heap->limit, (size_t) 1024 * 1024 * 1024);
+	size_t hard_limit = (heap->limit > (size_t) -1 - headroom) ? (size_t) -1 : heap->limit + headroom;
+
+	if (heap->real_size > heap->limit) {
+		/* memory_limit is changed while exceeded (e.g. reset by the fatal
+		 * error handler): neither move the hard limit up again, nor below
+		 * the current usage */
+		if (heap->hard_limit > hard_limit && heap->hard_limit >= heap->real_size) {
+			hard_limit = heap->hard_limit;
+		}
+		if (hard_limit < heap->real_size) {
+			hard_limit = (heap->real_size > (size_t) -1 - headroom) ? (size_t) -1 : heap->real_size + headroom;
+		}
+	}
+	heap->hard_limit = hard_limit;
+}
+
 ZEND_API void zend_mm_shutdown(zend_mm_heap *heap, int full_shutdown, int silent TSRMLS_DC)
 {
 	zend_mm_storage *storage;
@@ -1737,73 +1764,122 @@ ZEND_API void zend_mm_shutdown(zend_mm_h
 			heap->reserve = _zend_mm_alloc_int(heap, heap->reserve_size  ZEND_FILE_LINE_CC ZEND_FILE_LINE_EMPTY_CC);
 		}
 		heap->overflow = 0;
+		zend_mm_update_hard_limit(heap);
 	}
 }
 
-static void zend_mm_safe_error(zend_mm_heap *heap,
-	const char *format,
-	size_t limit,
-#if ZEND_DEBUG
-	const char *filename,
-	uint lineno,
-#endif
-	size_t size)
+static void zend_mm_error_location(const char **error_filename, uint *error_lineno)
 {
-	if (heap->reserve) {
-		_zend_mm_free_int(heap, heap->reserve ZEND_FILE_LINE_CC ZEND_FILE_LINE_EMPTY_CC);
-		heap->reserve = NULL;
+	TSRMLS_FETCH();
+
+	if (zend_is_compiling(TSRMLS_C)) {
+		*error_filename = zend_get_compiled_filename(TSRMLS_C);
+		*error_lineno = zend_get_compiled_lineno(TSRMLS_C);
+	} else if (EG(in_execution)) {
+		*error_filename = EG(active_op_array)?EG(active_op_array)->filename:NULL;
+		*error_lineno = EG(opline_ptr)?(*EG(opline_ptr))->lineno:0;
+	} else {
+		*error_filename = NULL;
+		*error_lineno = 0;
 	}
-	if (heap->overflow == 0) {
-		const char *error_filename;
-		uint error_lineno;
-		TSRMLS_FETCH();
-		if (zend_is_compiling(TSRMLS_C)) {
-			error_filename = zend_get_compiled_filename(TSRMLS_C);
-			error_lineno = zend_get_compiled_lineno(TSRMLS_C);
-		} else if (EG(in_execution)) {
-			error_filename = EG(active_op_array)?EG(active_op_array)->filename:NULL;
-			error_lineno = EG(opline_ptr)?(*EG(opline_ptr))->lineno:0;
-		} else {
-			error_filename = NULL;
-			error_lineno = 0;
-		}
-		if (!error_filename) {
-			error_filename = "Unknown";
-		}
-		heap->overflow = 1;
-		zend_try {
-			zend_error_noreturn(E_ERROR,
-				format,
-				limit,
-#if ZEND_DEBUG
-				filename,
-				lineno,
+	if (!*error_filename) {
+		*error_filename = "Unknown";
+	}
+}
+
+/* Real allocation failure (mmap/malloc): there is no safe way to continue */
+#if (defined (__GNUC__) && __GNUC__ > 2 ) && !defined(__INTEL_COMPILER) && !defined(DARWIN) && !defined(__hpux) && !defined(_AIX)
+static void zend_mm_out_of_memory(zend_mm_heap *heap, size_t size) __attribute__ ((noreturn));
 #endif
-				size);
-		} zend_catch {
-			if (heap->overflow == 2) {
-				fprintf(stderr, "\nFatal error: ");
-				fprintf(stderr,
-					format,
-					limit,
-#if ZEND_DEBUG
-					filename,
-					lineno,
+static void zend_mm_out_of_memory(zend_mm_heap *heap, size_t size)
+{
+	const char *error_filename;
+	uint error_lineno;
+
+	zend_mm_error_location(&error_filename, &error_lineno);
+	fprintf(stderr, "Out of memory (allocated %ld) (tried to allocate %lu bytes) in %s on line %d\n",
+		(long) heap->real_size, (unsigned long) size, error_filename, error_lineno);
+/* See http://support.microsoft.com/kb/190351 */
+#ifdef PHP_WIN32
+	fflush(stderr);
 #endif
-					size);
-				fprintf(stderr, " in %s on line %d\n", error_filename, error_lineno);
-			}
+	exit(1);
+}
+
+#if (defined (__GNUC__) && __GNUC__ > 2 ) && !defined(__INTEL_COMPILER) && !defined(DARWIN) && !defined(__hpux) && !defined(_AIX)
+static void zend_mm_hard_limit_error(zend_mm_heap *heap, size_t size) __attribute__ ((noreturn));
+#endif
+static void zend_mm_hard_limit_error(zend_mm_heap *heap, size_t size)
+{
+	const char *error_filename;
+	uint error_lineno;
+
+	zend_mm_error_location(&error_filename, &error_lineno);
+	fprintf(stderr, "Hard memory limit of %lu bytes exhausted (tried to allocate %lu bytes) in %s on line %d\n",
+		(unsigned long) heap->hard_limit, (unsigned long) size, error_filename, error_lineno);
 /* See http://support.microsoft.com/kb/190351 */
 #ifdef PHP_WIN32
-			fflush(stderr);
+	fflush(stderr);
+#endif
+	_exit(137);
+}
+
+/* Record a memory limit error, to be raised at the next safe point by
+ * zend_handle_delayed_oom(). Bailing out from here would leave whatever the
+ * caller was in the middle of initializing reachable by the shutdown
+ * sequence (CVE-2026-109618). */
+static void zend_mm_delayed_error(zend_mm_heap *heap, const char *format, ...)
+{
+	const char *error_filename;
+	uint error_lineno;
+	va_list args;
+	TSRMLS_FETCH();
+
+	if (EG(delayed_oom) != ZEND_OOM_STATE_NONE) {
+		return;
+	}
+
+	zend_mm_error_location(&error_filename, &error_lineno);
+
+	va_start(args, format);
+	vsnprintf(heap->oom_message, sizeof(heap->oom_message), format, args);
+	va_end(args);
+	snprintf(heap->oom_filename, sizeof(heap->oom_filename), "%s", error_filename);
+	heap->oom_lineno = error_lineno;
+
+	EG(delayed_oom) = ZEND_OOM_STATE_PENDING;
+}
+
+/* Called when an allocation of add_size bytes makes the heap grow beyond the
+ * soft limit (memory_limit). Does not return when the hard limit would be
+ * exceeded. */
+static void zend_mm_limit_exceeded(zend_mm_heap *heap, size_t add_size
+#if ZEND_DEBUG
+	, const char *filename, uint lineno
+#endif
+	, size_t size)
+{
+	if (add_size > heap->hard_limit || heap->real_size > heap->hard_limit - add_size) {
+		zend_mm_hard_limit_error(heap, size);
+	}
+	if (heap->overflow == 0) {
+#if ZEND_DEBUG
+		zend_mm_delayed_error(heap, "Allowed memory size of %ld bytes exhausted at %s:%d (tried to allocate %lu bytes)", (long) heap->limit, filename, lineno, (unsigned long) size);
+#else
+		zend_mm_delayed_error(heap, "Allowed memory size of %ld bytes exhausted (tried to allocate %lu bytes)", (long) heap->limit, (unsigned long) size);
 #endif
-		} zend_end_try();
-	} else {
-		heap->overflow = 2;
 	}
-	zend_bailout();
 }
 
+#if ZEND_DEBUG
+# define ZEND_MM_LIMIT_EXCEEDED(heap, add_size, size) \
+	zend_mm_limit_exceeded(heap, add_size, __zend_filename, __zend_lineno, size)
+#else
+# define ZEND_MM_LIMIT_EXCEEDED(heap, add_size, size) \
+	zend_mm_limit_exceeded(heap, add_size, size)
+#endif
+
+
 static zend_mm_free_block *zend_mm_search_large_block(zend_mm_heap *heap, size_t true_size)
 {
 	zend_mm_free_block *best_fit;
@@ -1965,18 +2041,14 @@ static void *_zend_mm_alloc_int(zend_mm_
 			segment_size = heap->block_size;
 		}
 
-		if (segment_size < true_size ||
-		    heap->real_size + segment_size > heap->limit) {
-			/* Memory limit overflow */
-#if ZEND_MM_CACHE
-			zend_mm_free_cache(heap);
-#endif
+		if (segment_size < true_size) {
+			/* Integer overflow */
 			HANDLE_UNBLOCK_INTERRUPTIONS();
-#if ZEND_DEBUG
-			zend_mm_safe_error(heap, "Allowed memory size of %ld bytes exhausted at %s:%d (tried to allocate %lu bytes)", heap->limit, __zend_filename, __zend_lineno, size);
-#else
-			zend_mm_safe_error(heap, "Allowed memory size of %ld bytes exhausted (tried to allocate %lu bytes)", heap->limit, size);
-#endif
+			zend_mm_out_of_memory(heap, size);
+		}
+		if (heap->real_size + segment_size > heap->limit) {
+			/* Memory limit overflow: report it later, see zend_mm_delayed_error() */
+			ZEND_MM_LIMIT_EXCEEDED(heap, segment_size, size);
 		}
 
 		segment = (zend_mm_segment *) ZEND_MM_STORAGE_ALLOC(segment_size);
@@ -1988,11 +2060,7 @@ static void *_zend_mm_alloc_int(zend_mm_
 #endif
 out_of_memory:
 			HANDLE_UNBLOCK_INTERRUPTIONS();
-#if ZEND_DEBUG
-			zend_mm_safe_error(heap, "Out of memory (allocated %ld) at %s:%d (tried to allocate %lu bytes)", heap->real_size, __zend_filename, __zend_lineno, size);
-#else
-			zend_mm_safe_error(heap, "Out of memory (allocated %ld) (tried to allocate %lu bytes)", heap->real_size, size);
-#endif
+			zend_mm_out_of_memory(heap, size);
 			return NULL;
 		}
 
@@ -2276,21 +2344,15 @@ realloc_segment:
 		}
 
 		segment_copy = (zend_mm_segment *) ((char *)mm_block - ZEND_MM_ALIGNED_SEGMENT_SIZE);
-		if (segment_size < true_size ||
-		    heap->real_size + segment_size - segment_copy->size > heap->limit) {
-			if (ZEND_MM_IS_FREE_BLOCK(next_block)) {
-				zend_mm_add_to_free_list(heap, (zend_mm_free_block *) next_block);
-			}
-#if ZEND_MM_CACHE
-			zend_mm_free_cache(heap);
-#endif
+		if (segment_size < true_size) {
+			/* Integer overflow */
 			HANDLE_UNBLOCK_INTERRUPTIONS();
-#if ZEND_DEBUG
-			zend_mm_safe_error(heap, "Allowed memory size of %ld bytes exhausted at %s:%d (tried to allocate %ld bytes)", heap->limit, __zend_filename, __zend_lineno, size);
-#else
-			zend_mm_safe_error(heap, "Allowed memory size of %ld bytes exhausted (tried to allocate %ld bytes)", heap->limit, size);
-#endif
-			return NULL;
+			zend_mm_out_of_memory(heap, size);
+		}
+		if (segment_size > segment_copy->size &&
+		    heap->real_size + (segment_size - segment_copy->size) > heap->limit) {
+			/* Memory limit overflow: report it later, see zend_mm_delayed_error() */
+			ZEND_MM_LIMIT_EXCEEDED(heap, segment_size - segment_copy->size, size);
 		}
 
 		segment = ZEND_MM_STORAGE_REALLOC(segment_copy, segment_size);
@@ -2300,11 +2362,7 @@ realloc_segment:
 #endif
 out_of_memory:
 			HANDLE_UNBLOCK_INTERRUPTIONS();
-#if ZEND_DEBUG
-			zend_mm_safe_error(heap, "Out of memory (allocated %ld) at %s:%d (tried to allocate %ld bytes)", heap->real_size, __zend_filename, __zend_lineno, size);
-#else
-			zend_mm_safe_error(heap, "Out of memory (allocated %ld) (tried to allocate %ld bytes)", heap->real_size, size);
-#endif
+			zend_mm_out_of_memory(heap, size);
 			return NULL;
 		}
 		heap->real_size += segment_size - segment->size;
@@ -2458,6 +2516,20 @@ ZEND_API size_t _zend_mem_block_size(voi
 	return _zend_mm_block_size(AG(mm_heap), ptr ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
 }
 
+/* Not reporting this as a fatal error: bailing out from an allocation leaves
+ * the caller's state inconsistent (CVE-2026-109618) */
+#if (defined (__GNUC__) && __GNUC__ > 2 ) && !defined(__INTEL_COMPILER) && !defined(DARWIN) && !defined(__hpux) && !defined(_AIX)
+static void zend_mm_safe_address_overflow(size_t nmemb, size_t size, size_t offset) __attribute__ ((noreturn));
+#endif
+static void zend_mm_safe_address_overflow(size_t nmemb, size_t size, size_t offset)
+{
+	char buf[256];
+
+	snprintf(buf, sizeof(buf), "Possible integer overflow in memory allocation (%lu * %lu + %lu)",
+		(unsigned long) nmemb, (unsigned long) size, (unsigned long) offset);
+	zend_mm_panic(buf);
+}
+
 #if defined(__GNUC__) && (defined(__native_client__) || defined(i386))
 
 static inline size_t safe_address(size_t nmemb, size_t size, size_t offset)
@@ -2472,7 +2544,7 @@ static inline size_t safe_address(size_t
 	       "rm"(offset));
 
 	if (UNEXPECTED(overflow)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
+		zend_mm_safe_address_overflow(nmemb, size, offset);
 		return 0;
 	}
 	return res;
@@ -2501,7 +2573,7 @@ static inline size_t safe_address(size_t
 
 #undef LP_SUFF
         if (UNEXPECTED(overflow)) {
-                zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
+                zend_mm_safe_address_overflow(nmemb, size, offset);
                 return 0;
         }
         return res;
@@ -2522,7 +2594,7 @@ static inline size_t safe_address(size_t
                "1"(0));
 
         if (UNEXPECTED(overflow)) {
-                zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
+                zend_mm_safe_address_overflow(nmemb, size, offset);
                 return 0;
         }
         return res;
@@ -2542,7 +2614,7 @@ static inline size_t safe_address(size_t
                "r"(offset));
 
         if (UNEXPECTED(overflow)) {
-                zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
+                zend_mm_safe_address_overflow(nmemb, size, offset);
                 return 0;
         }
         return res;
@@ -2555,7 +2627,7 @@ static inline size_t safe_address(size_t
 	zend_ulong64 res = (zend_ulong64)nmemb * (zend_ulong64)size + (zend_ulong64)offset;
 
 	if (UNEXPECTED(res > (zend_ulong64)0xFFFFFFFFL)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
+		zend_mm_safe_address_overflow(nmemb, size, offset);
 		return 0;
 	}
 	return (size_t) res;
@@ -2570,7 +2642,7 @@ static inline size_t safe_address(size_t
 	double _delta = (double)res - _d;
 
 	if (UNEXPECTED((_d + _delta ) != _d)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu * %zu + %zu)", nmemb, size, offset);
+		zend_mm_safe_address_overflow(nmemb, size, offset);
 		return 0;
 	}
 	return res;
@@ -2582,7 +2654,10 @@ ZEND_API void *_safe_emalloc_string(size
 {
 	size_t str_size = safe_address(nmemb, size, offset);
 	if (UNEXPECTED(str_size > INT_MAX)) {
-		zend_error_noreturn(E_ERROR, "String allocation overflow, max size is %d", INT_MAX);
+		char buf[64];
+
+		snprintf(buf, sizeof(buf), "String allocation overflow, max size is %d", INT_MAX);
+		zend_mm_panic(buf);
 	}
 	return emalloc_rel(str_size);
 }
@@ -2691,11 +2766,48 @@ ZEND_API char *zend_strndup(const char *
 }
 
 
+static void zend_mm_error_cb(int type, const char *error_filename, uint error_lineno, const char *format, ...)
+{
+	va_list args;
+
+	va_start(args, format);
+	zend_error_cb(type, error_filename, error_lineno, format, args);
+	va_end(args);
+}
+
+ZEND_API void zend_handle_delayed_oom(TSRMLS_D)
+{
+	zend_mm_heap *heap = AG(mm_heap);
+
+	if (EG(delayed_oom) != ZEND_OOM_STATE_PENDING) {
+		return;
+	}
+	EG(delayed_oom) = ZEND_OOM_STATE_HANDLING;
+
+	/* Let error reporting allocate beyond the soft limit */
+	heap->overflow = 1;
+
+	/* An exception may be in flight. Reporting it may run user code
+	 * (__toString()), which must not happen now. */
+	EG(exception) = NULL;
+
+	zend_try {
+		zend_mm_error_cb(E_ERROR, heap->oom_filename, heap->oom_lineno, "%s", heap->oom_message);
+	} zend_catch {
+	} zend_end_try();
+
+	heap->overflow = 0;
+	EG(delayed_oom) = ZEND_OOM_STATE_HANDLED;
+
+	zend_bailout();
+}
+
 ZEND_API int zend_set_memory_limit(size_t memory_limit)
 {
 	TSRMLS_FETCH();
 
 	AG(mm_heap)->limit = (memory_limit >= AG(mm_heap)->block_size) ? memory_limit : AG(mm_heap)->block_size;
+	zend_mm_update_hard_limit(AG(mm_heap));
 
 	return SUCCESS;
 }
