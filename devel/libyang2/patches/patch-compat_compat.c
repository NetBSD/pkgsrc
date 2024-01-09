$NetBSD: patch-compat_compat.c,v 1.1 2024/01/09 15:53:59 chopps Exp $

NetBSD has realpath() this is unneeded.

--- compat/compat.c.orig	2023-10-11 07:55:04.000000000 +0000
+++ compat/compat.c
@@ -268,20 +268,6 @@ realpath(const char *path, char *resolve
     }
     return resolved;
 }
-
-#elif defined (__NetBSD__)
-char *
-realpath(const char *path, char *resolved_path)
-{
-    ssize_t nbytes;
-
-    nbytes = readlink(path, resolved_path, PATH_MAX);
-    if (nbytes == -1) {
-        return NULL;
-    }
-    return resolved_path;
-}
-
 #else
 #error No realpath() implementation for this platform is available.
 #endif
