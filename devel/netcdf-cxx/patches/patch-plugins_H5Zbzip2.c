$NetBSD: patch-plugins_H5Zbzip2.c,v 1.1 2023/10/06 13:40:47 adam Exp $

Avoid missing symbols.

--- plugins/H5Zbzip2.c.orig	2023-10-06 13:31:12.412087559 +0000
+++ plugins/H5Zbzip2.c
@@ -201,7 +201,11 @@ size_t H5Z_filter_bzip2(unsigned int fla
 
   /* Always replace the input buffer with the output buffer. */
 
+#ifdef HAVE_H5FREE_MEMORY
   H5free_memory(*buf);
+#else
+  free(*buf);
+#endif
 
   *buf = outbuf;
   *buf_size = outbuflen;
@@ -209,7 +213,11 @@ size_t H5Z_filter_bzip2(unsigned int fla
 
  cleanupAndFail:
   if (outbuf)
+#ifdef HAVE_H5FREE_MEMORY
     H5free_memory(outbuf);
+#else
+    free(outbuf);
+#endif
 
   return 0;
 }
