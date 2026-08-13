$NetBSD: patch-quickjs.c,v 1.9 2026/08/13 18:11:24 wiz Exp $

- Portability patch for NetBSD.
- Fix SIGBUS on strict-alignment platforms (e.g. sparc, sparc64): the
  function bytecode's constant pool (an array of JSValue, which can
  hold a double/int64_t and needs 8-byte alignment) was suballocated
  at an offset that was only guaranteed 4-byte alignment, since none
  of the preceding JSFunctionBytecode fields force 8-byte alignment
  on their own. This crashed the first time a compiled script's
  constant pool was read or written, e.g.:

    # qjsc -s -c -o repl.c -m repl.js
    Bus error (core dumped)

    (gdb) bt
    #0  JS_WriteFunctionTag (obj=<optimized out>, s=0xefffccbc) at quickjs.c:37315
    37315           if (JS_WriteObjectRec(s, b->cpool[i]))

  Round cpool_offset up to 8 bytes in both the writer's allocation
  path (js_create_function) and the matching reader's allocation
  path (JS_ReadFunctionTag).

--- quickjs.c.orig	2026-06-04 12:26:08.000000000 +0000
+++ quickjs.c
@@ -69,7 +69,15 @@
 /* define to include Atomics.* operations which depend on the OS
    threads */
 #if !defined(__EMSCRIPTEN__)
+#ifdef __NetBSD__
+#ifdef __HAVE_ATOMICOPS64_OPS
 #define CONFIG_ATOMICS
+#else
+#undef CONFIG_ATOMICS
+#endif /* __HAVE_ATOMICOPS64_OPS */
+#else /* !__NetBSD__ */
+#define CONFIG_ATOMICS
+#endif /* __NetBSD__ */
 #endif
 
 #if !defined(__EMSCRIPTEN__)
@@ -2140,7 +2148,7 @@ static size_t js_def_malloc_usable_size(const void *pt
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize((void *)ptr);
-#elif defined(__EMSCRIPTEN__)
+#elif defined(__EMSCRIPTEN__) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__) || defined(__GLIBC__)
     return malloc_usable_size((void *)ptr);
@@ -36006,8 +36014,8 @@ static JSValue js_create_function(JSContext *ctx, JSFu
     } else {
         function_size = sizeof(*b);
     }
-    cpool_offset = function_size;
-    function_size += fd->cpool_count * sizeof(*fd->cpool);
+    cpool_offset = (function_size + 7) & ~7;
+    function_size = cpool_offset + fd->cpool_count * sizeof(*fd->cpool);
     vardefs_offset = function_size;
     function_size += (fd->arg_count + fd->var_count) * sizeof(*b->vardefs);
     closure_var_offset = function_size;
@@ -38682,8 +38690,8 @@ static JSValue JS_ReadFunctionTag(BCReaderState *s)
     } else {
         function_size = offsetof(JSFunctionBytecode, debug);
     }
-    cpool_offset = function_size;
-    function_size += (uint64_t)bc.cpool_count * sizeof(*bc.cpool);
+    cpool_offset = (function_size + 7) & ~7;
+    function_size = cpool_offset + bc.cpool_count * sizeof(*bc.cpool);
     vardefs_offset = function_size;
     function_size += (uint64_t)local_count * sizeof(*bc.vardefs);
     closure_var_offset = function_size;
