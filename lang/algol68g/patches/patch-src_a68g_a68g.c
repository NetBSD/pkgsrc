$NetBSD: patch-src_a68g_a68g.c,v 1.1 2022/03/02 01:41:34 ryoon Exp $

* Use header files from ${PREFIX}.

--- src/a68g/a68g.c.orig	2022-02-01 20:45:41.000000000 +0000
+++ src/a68g/a68g.c
@@ -448,7 +448,7 @@ static void compiler_interpreter (void)
       bufcat (options, " ", BUFFER_SIZE);
       bufcat (options, HAVE_PIC, BUFFER_SIZE);
 #endif
-      ASSERT (snprintf (cmd, SNPRINTF_SIZE, "gcc %s -c -o \"%s\" \"%s\"", options, FILE_BINARY_NAME (&A68_JOB), FILE_OBJECT_NAME (&A68_JOB)) >= 0);
+      ASSERT (snprintf (cmd, SNPRINTF_SIZE, "gcc %s -I@PREFIX@/include -c -o \"%s\" \"%s\"", options, FILE_BINARY_NAME (&A68_JOB), FILE_OBJECT_NAME (&A68_JOB)) >= 0);
       ABEND (system (cmd) != 0, ERROR_ACTION, cmd);
       ASSERT (snprintf (cmd, SNPRINTF_SIZE, "ld -export-dynamic -shared -o \"%s\" \"%s\"", FILE_LIBRARY_NAME (&A68_JOB), FILE_BINARY_NAME (&A68_JOB)) >= 0);
       ABEND (system (cmd) != 0, ERROR_ACTION, cmd);
