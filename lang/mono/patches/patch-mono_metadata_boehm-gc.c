$NetBSD: patch-mono_metadata_boehm-gc.c,v 1.1 2018/07/27 20:02:40 jperkin Exp $

Support newer boehm-gc.

--- mono/metadata/boehm-gc.c.orig	2015-08-25 22:09:13.000000000 +0000
+++ mono/metadata/boehm-gc.c
@@ -1334,7 +1334,11 @@ mono_gc_toggleref_add (MonoObject *objec
 void
 mono_gc_toggleref_register_callback (MonoToggleRefStatus (*proccess_toggleref) (MonoObject *obj))
 {
+#if GC_VERSION_MAJOR >= 7
+	GC_set_toggleref_func ((GC_ToggleRefStatus (*) (GC_PTR obj)) proccess_toggleref);
+#else
 	GC_toggleref_register_callback ((int (*) (GC_PTR obj)) proccess_toggleref);
+#endif
 }
 
 /* Test support code */
@@ -1383,7 +1387,11 @@ mono_gc_register_finalizer_callbacks (Mo
 
 	fin_callbacks = *callbacks;
 
+#if GC_VERSION_MAJOR >= 7
+	GC_set_await_finalize_proc ((void (*) (GC_PTR))fin_notifier);
+#else
 	GC_set_finalizer_notify_proc ((void (*) (GC_PTR))fin_notifier);
+#endif
 }
 
 #endif /* no Boehm GC */
