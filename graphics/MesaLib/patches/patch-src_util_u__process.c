$NetBSD: patch-src_util_u__process.c,v 1.1 2022/03/13 15:52:50 tnn Exp $

atexit() is not a good idea in shared libraries.

--- src/util/u_process.c.orig	2021-07-14 20:04:59.260044300 +0000
+++ src/util/u_process.c
@@ -48,9 +48,15 @@
 
 static char *path = NULL;
 
-static void __freeProgramPath()
+#if defined(HAVE_NOATEXIT)
+static void __attribute__((__destructor__))
+#else
+static void
+#endif
+__freeProgramPath()
 {
-   free(path);
+   if (path)
+     free(path);
    path = NULL;
 }
 
@@ -68,7 +74,9 @@ __getProgramName()
        */
       if (!path) {
          path = realpath("/proc/self/exe", NULL);
+#if !defined(HAVE_NOATEXIT)
          atexit(__freeProgramPath);
+#endif
       }
 
       if (path && strncmp(path, program_invocation_name, strlen(path)) == 0) {
