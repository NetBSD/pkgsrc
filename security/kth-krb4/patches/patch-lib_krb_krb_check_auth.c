$NetBSD: patch-lib_krb_krb_check_auth.c,v 1.1 2011/11/28 19:33:13 marino Exp $

--- lib/krb/krb_check_auth.c.orig	1999-12-02 16:58:42.000000000 +0000
+++ lib/krb/krb_check_auth.c
@@ -50,7 +50,11 @@ krb_check_auth(KTEXT packet,
 	       u_int32_t checksum,
 	       MSG_DAT *msg_data,
 	       des_cblock *session,
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	       des_key_schedule schedule,
+#else
 	       struct des_ks_struct *schedule,
+#endif
 	       struct sockaddr_in *laddr,
 	       struct sockaddr_in *faddr)
 {
