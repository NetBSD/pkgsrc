$NetBSD: patch-lib_krb_rd_priv.c,v 1.1 2011/11/28 19:33:13 marino Exp $

--- lib/krb/rd_priv.c.orig	2001-09-16 22:41:58.000000000 +0000
+++ lib/krb/rd_priv.c
@@ -57,7 +57,12 @@ RCSID("$Id: rd_priv.c,v 1.30 2001/09/16
 
 int32_t
 krb_rd_priv(void *in, u_int32_t in_length, 
-	    struct des_ks_struct *schedule, des_cblock *key, 
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	    des_key_schedule schedule,
+#else
+	    struct des_ks_struct *schedule,
+#endif
+	    des_cblock *key,
 	    struct sockaddr_in *sender, struct sockaddr_in *receiver, 
 	    MSG_DAT *m_data)
 {
