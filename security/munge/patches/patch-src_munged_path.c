$NetBSD: patch-src_munged_path.c,v 1.1 2024/05/18 22:31:06 bacon Exp $

# Use local strlcpy() without collision

--- src/munged/path.c.orig	2024-05-18 21:58:24.907978477 +0000
+++ src/munged/path.c
@@ -81,7 +81,7 @@ path_canonicalize (const char *src, char
         return (-1);
     }
     if ((dst != NULL) && (dstlen > 0)) {
-        n = strlcpy (dst, buf, dstlen);
+        n = __munge_strlcpy (dst, buf, dstlen);
     }
     return (n);
 }
@@ -97,7 +97,7 @@ path_dirname (const char *src, char *dst
         errno = EINVAL;
         return (-1);
     }
-    if (strlcpy (dst, src, dstlen) >= dstlen) {
+    if (__munge_strlcpy (dst, src, dstlen) >= dstlen) {
         errno = ENAMETOOLONG;
         return (-1);
     }
