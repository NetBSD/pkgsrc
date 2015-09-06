$NetBSD: patch-srtp_srtp.c,v 1.1 2015/09/06 14:02:08 joerg Exp $

--- srtp/srtp.c.orig	2006-07-18 19:45:46.000000000 +0000
+++ srtp/srtp.c
@@ -1905,3 +1905,14 @@ srtp_profile_get_master_salt_length(srtp
     return 0;  /* indicate error by returning a zero */
   }
 }
+
+err_status_t
+srtp_shutdown(void) {
+  err_status_t status;
+
+  /* shutdown the crypto kernel */
+  status = crypto_kernel_shutdown();
+  if (status)
+    return status;
+  return err_status_ok;
+}
