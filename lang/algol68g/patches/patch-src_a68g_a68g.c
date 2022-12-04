$NetBSD: patch-src_a68g_a68g.c,v 1.2 2022/12/04 17:11:13 rhialto Exp $

* Add -rpath=. to the linker command line, so that --compile works.
  Otherwise, you get errors like

  test-set$ a68g --compile 20-quicksort.a68 
  [20-quicksort.a68]
  test-set$ ./20-quicksort
  [.a68g.tmp.20-quicksort]
  a68g: exiting: ./src/a68g/a68g.c: 497: cannot resolve symbol, /usr/pkg/bin/a68g: Shared object ".a68g.tmp.20-quicksort.so" not found

--- src/a68g/a68g.c.orig	2022-11-06 16:02:39.000000000 +0000
+++ src/a68g/a68g.c
@@ -437,7 +437,7 @@ void compiler_interpreter (void)
 #endif
       ASSERT (snprintf (cmd, SNPRINTF_SIZE, "%s -I%s %s -c -o \"%s\" \"%s\"", C_COMPILER, INCLUDEDIR, options, FILE_BINARY_NAME (&A68_JOB), FILE_OBJECT_NAME (&A68_JOB)) >= 0);
       ABEND (system (cmd) != 0, ERROR_ACTION, cmd);
-      ASSERT (snprintf (cmd, SNPRINTF_SIZE, "ld -export-dynamic -shared -o \"%s\" \"%s\"", FILE_LIBRARY_NAME (&A68_JOB), FILE_BINARY_NAME (&A68_JOB)) >= 0);
+      ASSERT (snprintf (cmd, SNPRINTF_SIZE, "ld -rpath=. -export-dynamic -shared -o \"%s\" \"%s\"", FILE_LIBRARY_NAME (&A68_JOB), FILE_BINARY_NAME (&A68_JOB)) >= 0);
       ABEND (system (cmd) != 0, ERROR_ACTION, cmd);
       a68_rm (FILE_BINARY_NAME (&A68_JOB));
     }
