$NetBSD: patch-include_srtp.h,v 1.1 2015/09/06 14:02:08 joerg Exp $

--- include/srtp.h.orig	2006-07-12 22:22:10.000000000 +0000
+++ include/srtp.h
@@ -258,6 +258,16 @@ err_status_t
 srtp_init(void);
 
 /**
+ * @brief srtp_shutdown() releases allocated resources
+ *
+ * @warning After calling this function srtp functions are no longer
+ * available.
+ */
+
+err_status_t
+srtp_shutdown(void);
+
+/**
  * @brief srtp_protect() is the Secure RTP sender-side packet processing
  * function.
  * 
