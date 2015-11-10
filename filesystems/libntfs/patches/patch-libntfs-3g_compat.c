$NetBSD: patch-libntfs-3g_compat.c,v 1.1 2015/11/10 17:45:22 adam Exp $

Add missing function for NetBSD.

--- libntfs-3g/compat.c.orig	2015-11-10 14:27:56.000000000 +0000
+++ libntfs-3g/compat.c
@@ -248,3 +248,12 @@ char *strsep(char **stringp, const char 
  *************************************************************/
 #endif /* HAVE_STRSEP */
 
+#if defined(__NetBSD__)
+#include <fuse.h>
+
+int fuse_version(void)
+{
+    return FUSE_VERSION;
+}
+
+#endif /* __NetBSD__ */
