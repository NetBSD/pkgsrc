$NetBSD: patch-lib_krb_krb-protos.h,v 1.1 2011/11/28 19:33:13 marino Exp $

--- lib/krb/krb-protos.h.orig	2001-08-26 01:46:51.000000000 +0000
+++ lib/krb/krb-protos.h
@@ -177,7 +177,11 @@ krb_check_auth __P((
 	u_int32_t checksum,
 	MSG_DAT *msg_data,
 	des_cblock *session,
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	des_key_schedule schedule,
+#else
 	struct des_ks_struct *schedule,
+#endif
 	struct sockaddr_in *laddr,
 	struct sockaddr_in *faddr));
 
@@ -457,7 +461,11 @@ krb_mk_priv __P((
 	void *in,
 	void *out,
 	u_int32_t length,
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	des_key_schedule schedule,
+#else
 	struct des_ks_struct *schedule,
+#endif
 	des_cblock *key,
 	struct sockaddr_in *sender,
 	struct sockaddr_in *receiver));
@@ -540,7 +548,11 @@ int32_t KRB_LIB_FUNCTION
 krb_rd_priv __P((
 	void *in,
 	u_int32_t in_length,
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	des_key_schedule schedule,
+#else
 	struct des_ks_struct *schedule,
+#endif
 	des_cblock *key,
 	struct sockaddr_in *sender,
 	struct sockaddr_in *receiver,
@@ -583,7 +595,11 @@ krb_recvauth __P((
 	struct sockaddr_in *laddr,
 	AUTH_DAT *kdata,
 	char *filename,
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	des_key_schedule schedule,
+#else
 	struct des_ks_struct *schedule,
+#endif
 	char *version));
 
 int KRB_LIB_FUNCTION
@@ -597,7 +613,11 @@ krb_sendauth __P((
 	u_int32_t checksum,
 	MSG_DAT *msg_data,
 	CREDENTIALS *cred,
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	des_key_schedule schedule,
+#else
 	struct des_ks_struct *schedule,
+#endif
 	struct sockaddr_in *laddr,
 	struct sockaddr_in *faddr,
 	char *version));
