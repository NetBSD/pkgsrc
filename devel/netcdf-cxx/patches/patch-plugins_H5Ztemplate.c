$NetBSD: patch-plugins_H5Ztemplate.c,v 1.1 2023/10/06 13:40:47 adam Exp $

Avoid missing symbols.

--- plugins/H5Ztemplate.c.orig	2023-10-06 13:30:10.395421663 +0000
+++ plugins/H5Ztemplate.c
@@ -92,13 +92,21 @@ size_t H5Z_filter_xxxx(unsigned int flag
   }
 
   /* Always replace the input buffer with the output buffer. */
+#ifdef HAVE_H5FREE_MEMORY
   H5free_memory(*buf);
+#else
+  free(*buf);
+#endif
   *buf = outbuf;
   *buf_size = outbuflen;
   return outdatalen;
 
  cleanupAndFail:
   if (outbuf)
+#ifdef HAVE_H5FREE_MEMORY
     H5free_memory(outbuf);
+#else
+    free(outbud);
+#endif
   return 0;
 }
