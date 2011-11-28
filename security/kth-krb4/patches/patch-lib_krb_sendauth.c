$NetBSD: patch-lib_krb_sendauth.c,v 1.1 2011/11/28 19:33:13 marino Exp $

--- lib/krb/sendauth.c.orig	1999-09-16 20:41:55.000000000 +0000
+++ lib/krb/sendauth.c
@@ -103,7 +103,11 @@ krb_sendauth(int32_t options,	/* bit-pat
 	     u_int32_t checksum, /* checksum to include in request */
 	     MSG_DAT *msg_data,	/* mutual auth MSG_DAT (return) */
 	     CREDENTIALS *cred,	/* credentials (return) */
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	     des_key_schedule schedule,
+#else
 	     struct des_ks_struct *schedule, /* key schedule (return) */
+#endif
 	     struct sockaddr_in *laddr, /* local address */
 	     struct sockaddr_in *faddr,	/* address of foreign host on fd */
 	     char *version)	/* version string */
