$NetBSD: patch-src_unix_netbsd.c,v 1.3 2020/07/29 10:20:56 wiz Exp $

Check for KERN_PROC_PATHNAME before using it, or use fallback implementation.

--- src/unix/netbsd.c.orig	2017-10-02 23:30:27.000000000 +0000
+++ src/unix/netbsd.c
@@ -66,6 +66,7 @@ void uv_loadavg(double avg[3]) {
 
 
 int uv_exepath(char* buffer, size_t* size) {
+#if defined(KERN_PROC_PATHNAME)
   /* Intermediate buffer, retrieving partial path name does not work
    * As of NetBSD-8(beta), vnode->path translator does not handle files
    * with longer names than 31 characters.
@@ -93,6 +94,22 @@ int uv_exepath(char* buffer, size_t* siz
 
   /* Set new size. */
   *size = strlen(buffer);
+#else
+  ssize_t n;
+
+  if (buffer == NULL || size == NULL || *size == 0)
+    return -EINVAL;
+
+  n = *size - 1;
+  if (n > 0)
+    n = readlink("/proc/self/exe", buffer, n);
+
+  if (n == -1)
+    return -errno;
+
+  buffer[n] = '\0';
+  *size = n;
+#endif
 
   return 0;
 }
