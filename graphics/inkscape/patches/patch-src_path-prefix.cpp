$NetBSD: patch-src_path-prefix.cpp,v 1.2 2021/07/02 06:59:15 wiz Exp $

Add NetBSD support in get_program_name().

--- src/path-prefix.cpp.orig	2021-05-17 19:25:49.000000000 +0000
+++ src/path-prefix.cpp
@@ -20,6 +20,11 @@
 #include <mach-o/dyld.h> // for _NSGetExecutablePath
 #endif
 
+#ifdef __NetBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #include <cassert>
 #include <glib.h>
 #include <glibmm.h>
@@ -123,6 +128,15 @@ char const *get_program_name()
         if (!program_name) {
             g_warning("get_program_name() - g_file_read_link failed");
         }
+#elif defined(__NetBSD__)
+        static const int name[] = {CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME};
+        char path[MAXPATHLEN];
+        size_t len = sizeof(path);
+        if (sysctl(name, __arraycount(name), path, &len, NULL, 0) == 0) {
+            program_name = realpath(path, nullptr);
+        } else {
+            g_warning("get_program_name() - sysctl failed");
+        }
 #else
 #warning get_program_name() - no known way to obtain executable name on this platform
         g_info("get_program_name() - no known way to obtain executable name on this platform");
