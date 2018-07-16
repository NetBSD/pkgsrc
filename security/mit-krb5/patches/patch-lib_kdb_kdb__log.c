$NetBSD: patch-lib_kdb_kdb__log.c,v 1.1 2018/07/16 10:26:40 jperkin Exp $

Fix mmap/munmap -Werror=incompatible-pointer-types

--- lib/kdb/kdb_log.c.orig	2018-05-03 14:34:47.000000000 +0000
+++ lib/kdb/kdb_log.c
@@ -489,7 +489,7 @@ ulog_map(krb5_context context, const cha
             return errno;
     }
 
-    ulog = mmap(0, MAXLOGLEN, PROT_READ | PROT_WRITE, MAP_SHARED, ulogfd, 0);
+    ulog = (kdb_hlog_t *)mmap(0, MAXLOGLEN, PROT_READ | PROT_WRITE, MAP_SHARED, ulogfd, 0);
     if (ulog == MAP_FAILED) {
         /* Can't map update log file to memory. */
         close(ulogfd);
@@ -681,7 +681,11 @@ ulog_fini(krb5_context context)
     if (log_ctx == NULL)
         return;
     if (log_ctx->ulog != NULL)
+#ifdef __sun
+        munmap((caddr_t)log_ctx->ulog, MAXLOGLEN);
+#else
         munmap(log_ctx->ulog, MAXLOGLEN);
+#endif
     free(log_ctx);
     context->kdblog_context = NULL;
 }
