$NetBSD: patch-src_estream.c,v 1.1.2.2 2014/10/29 20:11:31 tron Exp $

Don't use atexit(), since this library mey be dlopen()ed
and dlclose()d before exit() is called.

Instead mark the do_deinit() function as a destructor.

--- src/estream.c.orig	2014-09-11 09:38:21.000000000 +0000
+++ src/estream.c
@@ -471,6 +471,7 @@ do_list_remove (estream_t stream, int wi
 
 
 
+__attribute__((destructor,used))
 static void
 do_deinit (void)
 {
@@ -503,7 +504,16 @@ _gpgrt_es_init (void)
   if (!initialized)
     {
       initialized = 1;
+#if 0
+      /* This library may be unloaded via dlclose() before
+       * exit() is called, causing the atexit handler to try
+       * to jump into unmapped address space, causing a segfault.
+       * This has been observed with apache and php.  Instead, use
+       * the destructor attribute, since that will cause it
+       * to be called on dlclose() as well.
+       */
       atexit (do_deinit);
+#endif
     }
   return 0;
 }
