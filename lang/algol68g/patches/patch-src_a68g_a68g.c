$NetBSD: patch-src_a68g_a68g.c,v 1.3 2022/12/04 18:30:39 rhialto Exp $

* Use an explicit directory name to store (and later dlopen) the .so file,
  so that --compile works.  Otherwise, you get errors like

  test-set$ a68g --compile 20-quicksort.a68 
  [20-quicksort.a68]
  test-set$ ./20-quicksort
  [.a68g.tmp.20-quicksort]
  a68g: exiting: ./src/a68g/a68g.c: 497: cannot resolve symbol, /usr/pkg/bin/a68g: Shared object ".a68g.tmp.20-quicksort.so" not found

--- src/a68g/a68g.c.orig	2022-11-06 16:02:39.000000000 +0000
+++ src/a68g/a68g.c
@@ -480,7 +480,7 @@ void compiler_interpreter (void)
       struct stat srcstat, objstat;
       int ret;
       announce_phase ("dynamic linker");
-      ASSERT (snprintf (libname, SNPRINTF_SIZE, "%s", FILE_LIBRARY_NAME (&A68_JOB)) >= 0);
+      ASSERT (snprintf (libname, SNPRINTF_SIZE, "./%s", FILE_LIBRARY_NAME (&A68_JOB)) >= 0);
 // Check whether we are doing something rash.
       ret = stat (FILE_SOURCE_NAME (&A68_JOB), &srcstat);
       ABEND (ret != 0, ERROR_ACTION, FILE_SOURCE_NAME (&A68_JOB));
