$NetBSD: patch-lib_kadm_kadm_cli_wrap.c,v 1.1 2011/11/28 19:33:13 marino Exp $

--- lib/kadm/kadm_cli_wrap.c.orig	2011-11-28 02:10:03.761978000 +0000
+++ lib/kadm/kadm_cli_wrap.c
@@ -138,7 +143,12 @@ kadm_cli_conn(void)
 /* takes in the sess_key and key_schedule and sets them appropriately */
 static int
 kadm_cli_keyd(des_cblock (*s_k), /* session key */
-	      struct des_ks_struct *s_s) /* session key schedule */
+#if defined(__DragonFly__) || defined (__FreeBSD__)
+	      des_key_schedule s_s
+#else
+	      struct des_ks_struct *s_s
+#endif
+) /* session key schedule */
 {
 	CREDENTIALS cred;	       /* to get key data */
 	int stat;
