$NetBSD: patch-lib_kdb_kdb__log.c,v 1.2 2020/04/09 10:57:05 adam Exp $

Fix mmap/munmap -Werror=incompatible-pointer-types

--- lib/kdb/kdb_log.c.orig	2020-02-12 17:21:58.000000000 +0000
+++ lib/kdb/kdb_log.c
@@ -498,7 +498,7 @@ ulog_map(krb5_context context, const cha
         }
     }
 
-    ulog = mmap(0, MAXLOGLEN, PROT_READ | PROT_WRITE, MAP_SHARED,
+    ulog = (kdb_hlog_t *)mmap(0, MAXLOGLEN, PROT_READ | PROT_WRITE, MAP_SHARED,
                 log_ctx->ulogfd, 0);
     if (ulog == MAP_FAILED) {
         retval = errno;
@@ -680,7 +680,11 @@ ulog_fini(krb5_context context)
     if (log_ctx == NULL)
         return;
     if (log_ctx->ulog != NULL)
+#ifdef __sun
+        munmap((caddr_t)log_ctx->ulog, MAXLOGLEN);
+#else
         munmap(log_ctx->ulog, MAXLOGLEN);
+#endif
     if (log_ctx->ulogfd != -1)
         close(log_ctx->ulogfd);
     free(log_ctx);
