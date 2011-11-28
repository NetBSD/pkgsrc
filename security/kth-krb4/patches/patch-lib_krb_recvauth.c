$NetBSD: patch-lib_krb_recvauth.c,v 1.1 2011/11/28 19:33:13 marino Exp $

--- lib/krb/recvauth.c.orig	2001-08-26 02:52:18.000000000 +0000
+++ lib/krb/recvauth.c
@@ -108,7 +108,11 @@ krb_recvauth(int32_t options,	/* bit-pat
 	     struct sockaddr_in *laddr,	/* local address */
 	     AUTH_DAT *kdata,	/* kerberos data (returned) */
 	     char *filename,	/* name of file with service keys */
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	     des_key_schedule schedule,
+#else
 	     struct des_ks_struct *schedule, /* key schedule (return) */
+#endif
 	     char *version)	/* version string (filled in) */
 {
     char krb_vers[KRB_SENDAUTH_VLEN + 1]; /* + 1 for the null terminator */
