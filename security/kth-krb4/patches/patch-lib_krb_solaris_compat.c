$NetBSD: patch-lib_krb_solaris_compat.c,v 1.1 2011/11/28 19:33:13 marino Exp $

--- lib/krb/solaris_compat.c.orig	1999-12-02 16:58:44.000000000 +0000
+++ lib/krb/solaris_compat.c
@@ -42,7 +42,12 @@ RCSID("$Id: solaris_compat.c,v 1.4 1999/
 
 int32_t
 _C0095C2A(void *in, void *out, u_int32_t length, 
-	  struct des_ks_struct *schedule, des_cblock *key, 
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	des_key_schedule schedule,
+#else
+	  struct des_ks_struct *schedule,
+#endif
+	  des_cblock *key,
 	  struct sockaddr_in *sender, struct sockaddr_in *receiver)
 {
     return krb_mk_priv (in, out, length, schedule, key, sender, receiver);
@@ -50,7 +55,12 @@ _C0095C2A(void *in, void *out, u_int32_t
 
 int32_t
 _C0095C2B(void *in, u_int32_t in_length, 
-	  struct des_ks_struct *schedule, des_cblock *key, 
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	  des_key_schedule schedule,
+#else
+	  struct des_ks_struct *schedule,
+#endif
+	  des_cblock *key,
 	  struct sockaddr_in *sender, struct sockaddr_in *receiver, 
 	  MSG_DAT *m_data)
 {
