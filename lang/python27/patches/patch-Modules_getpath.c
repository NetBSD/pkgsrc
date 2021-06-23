$NetBSD: patch-Modules_getpath.c,v 1.4 2021/06/23 18:30:24 schmonz Exp $

* from cygport 2.7.3-getpath-exe-extension.patch

--- Modules/getpath.c.orig	2021-06-22 19:20:43.000000000 +0000
+++ Modules/getpath.c
@@ -8,6 +8,7 @@
 
 #ifdef __APPLE__
 #include <mach-o/dyld.h>
+#include <AvailabilityMacros.h>
 #endif
 
 /* Search in some common locations for the associated Python libraries.
@@ -428,6 +429,28 @@ calculate_path(void)
                         if (isxfile(progpath))
                                 break;
 
+#ifdef __CYGWIN__
+                        /*
+                         * Cygwin automatically removes the ".exe" extension from argv[0]
+                         * to make programs feel like they are in a more Unix-like
+                         * environment.  Unfortunately, this can make it problemmatic for
+                         * Cygwin to distinguish between a directory and an executable with
+                         * the same name excluding the ".exe" extension.  For example, the
+                         * Cygwin Python build directory has a "Python" directory and a
+                         * "python.exe" executable.  This causes isxfile() to erroneously
+                         * return false.  If isdir() returns true and there is enough space
+                         * to append the ".exe" extension, then we try again with the
+                         * extension appended.
+                         */
+#define EXE ".exe"
+                        if (isdir(progpath) && strlen(progpath) + strlen(EXE) <= MAXPATHLEN)
+                        {
+                            strcat(progpath, EXE);
+                            if (isxfile(progpath))
+                                break;
+                        }
+#endif /* __CYGWIN__ */
+
                         if (!delim) {
                                 progpath[0] = '\0';
                                 break;
