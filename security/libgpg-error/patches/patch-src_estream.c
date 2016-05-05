$NetBSD: patch-src_estream.c,v 1.3 2016/05/05 11:34:49 wiz Exp $

Don't use atexit(), since this library mey be dlopen()ed
and dlclose()d before exit() is called.

Instead mark the do_deinit() function as a destructor.

https://bugs.g10code.com/gnupg/issue1749

--- src/estream.c.orig	2016-04-05 13:44:10.000000000 +0000
+++ src/estream.c
@@ -529,6 +529,7 @@ do_list_remove (estream_t stream, int wi
 /*
  * The atexit handler for this estream module.
  */
+__attribute__((destructor,used))
 static void
 do_deinit (void)
 {
@@ -560,7 +561,16 @@ _gpgrt_es_init (void)
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
