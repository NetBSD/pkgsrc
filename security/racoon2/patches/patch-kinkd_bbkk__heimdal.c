$NetBSD: patch-kinkd_bbkk__heimdal.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Avoid deprecated API's
Include private header since we are using private functions
Fix function calls with missing args

--- kinkd/bbkk_heimdal.c.orig	2007-08-03 01:42:24.000000000 -0400
+++ kinkd/bbkk_heimdal.c	2018-05-28 21:07:22.720866945 -0400
@@ -40,6 +40,10 @@
 #include <string.h>
 #if defined(HAVE_KRB5_KRB5_H)
 # include <krb5/krb5.h>
+# include <openssl/evp.h>
+typedef void *krb5_pk_init_ctx;
+# include <krb5/pkinit_asn1.h>
+# include <krb5/krb5-private.h>
 #else
 # include <krb5.h>
 #endif
@@ -147,7 +151,7 @@
 	if (DEBUG_KRB5() && cause != NULL)
 		kinkd_log(KLLV_DEBUG,
 		    "bbkk: %s: %s\n",
-		    cause, krb5_get_err_text(con->context, ret));
+		    cause, krb5_get_error_message(con->context, ret));
 	if (con->rcache != NULL)
 		krb5_rc_close(con->context, con->rcache);
 	if (con->ccache != NULL)
@@ -185,7 +189,7 @@
 {
 	krb5_error_code ret;
 	krb5_principal principal;
-	krb5_get_init_creds_opt opt;
+	krb5_get_init_creds_opt *opt;
 	krb5_creds cred;
 	krb5_keytab kt;
 	krb5_deltat start_time = 0;
@@ -198,7 +202,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_parse_name: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
 	ret = krb5_kt_default(con->context, &kt);
@@ -206,25 +210,26 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_kt_default: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		krb5_free_principal(con->context, principal);
 		return ret;
 	}
 
 	memset(&cred, 0, sizeof(cred));
-	krb5_get_init_creds_opt_init(&opt);
+	krb5_get_init_creds_opt_alloc(con->context, &opt);
 	krb5_get_init_creds_opt_set_default_flags(con->context, "kinit",
-	    principal->realm, &opt);	/* XXX may not be kinit... */
+	    principal->realm, opt);	/* XXX may not be kinit... */
 
 	ret = krb5_get_init_creds_keytab(con->context, &cred, principal, kt,
-	    start_time, NULL /* server */, &opt);
+	    start_time, NULL /* server */, opt);
 	krb5_kt_close(con->context, kt);
 	krb5_free_principal(con->context, principal);
+	krb5_get_init_creds_opt_free(con->context, opt);
 	if (ret != 0) {
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_get_init_creds_keytab: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
 
@@ -236,10 +241,10 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_cc_store_cred: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
-	krb5_free_creds_contents(con->context, &cred);
+	krb5_free_cred_contents(con->context, &cred);
 
 	return 0;
 }
@@ -261,7 +266,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_parse_name: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
 	ret = krb5_parse_name(con->context, cprinc_str, &client);
@@ -269,7 +274,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_parse_name: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		krb5_free_principal(con->context, server);
 		return ret;
 	}
@@ -292,7 +297,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_cc_remove_cred: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		krb5_free_principal(con->context, client);
 		krb5_free_principal(con->context, server);
 		return ret;
@@ -311,7 +316,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_get_credentials: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
 	*cred = (void *)out_cred;
@@ -354,7 +359,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_copy_creds_contents: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		goto cleanup;
 	}
 	int_auth_con = NULL;
@@ -364,12 +369,12 @@
 	 */
 	ret = krb5_mk_req_extended(con->context, &int_auth_con,
 	    AP_OPTS_MUTUAL_REQUIRED, NULL /* in_data */, &cred_copy, &ap_req);
-	krb5_free_creds_contents(con->context, &cred_copy);
+	krb5_free_cred_contents(con->context, &cred_copy);
 	if (ret != 0) {
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_mk_req_extended: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		goto cleanup;
 	}
 
@@ -414,7 +419,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_rd_rep: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
 
@@ -462,7 +467,7 @@
 		if (ret != 0) {
 			kinkd_log(KLLV_SYSERR,
 			    "krb5e_force_get_key: (%d) %s\n",
-			    ret, krb5_get_err_text(con->context, ret));
+			    ret, krb5_get_error_message(con->context, ret));
 			krb5_auth_con_free(con->context, auth_context);
 			return ret;
 		}
@@ -470,7 +475,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_rd_req: (%d)%s\n",
-			    saveret, krb5_get_err_text(con->context, saveret));
+			    saveret, krb5_get_error_message(con->context, saveret));
 		krb5_auth_con_free(con->context, auth_context);
 		return saveret;
 	}
@@ -492,7 +497,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_rc_store: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		if (ticket != NULL)
 			krb5_free_ticket(con->context, ticket);
 		krb5_auth_con_free(con->context, auth_context);
@@ -507,7 +512,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_mk_rep: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		/*
 		 * XXX Heimdal-0.6.x
 		 * Heimdal-0.6.x frees only ticket contents, not containter;
@@ -536,7 +541,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_rd_req: (%d)%s\n",
-			    saveret, krb5_get_err_text(con->context, saveret));
+			    saveret, krb5_get_error_message(con->context, saveret));
 		if (ticket != NULL)
 			krb5_free_ticket(con->context, ticket);
 		return saveret;
@@ -584,7 +589,7 @@
 	time_t ctime, *ctimep;
 	int cusec, *cusecp;
 
-	e_text = krb5_get_err_text(con->context, ecode);
+	e_text = krb5_get_error_message(con->context, ecode);
 	if (ecode < KRB5KDC_ERR_NONE || KRB5_ERR_RCSID <= ecode) {
 		kinkd_log(KLLV_SYSWARN,
 		    "non protocol errror (%d), use GENERIC\n", ecode);
@@ -609,7 +614,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_mk_error: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
 
@@ -635,7 +640,7 @@
 		if (DEBUG_KRB5())
 			kinkd_log(KLLV_DEBUG,
 			    "bbkk: krb5_rd_error: %s\n",
-			    krb5_get_err_text(con->context, ret));
+			    krb5_get_error_message(con->context, ret));
 		return ret;
 	}
 
@@ -926,7 +931,7 @@
 	if (con == NULL)
 		return "Failed in initialization, so no message is available";
 	else
-		return krb5_get_err_text(con->context, ecode);
+		return krb5_get_error_message(con->context, ecode);
 }
 
 
@@ -951,7 +956,7 @@
 	keyblock = NULL;
 
 	if ((t = (krb5_ticket *)malloc(sizeof(*t))) == NULL) {
-		krb5_clear_error_string(context);
+		krb5_clear_error_message(context);
 		return ENOMEM;
 	}
 	*t = t0;
@@ -966,14 +971,14 @@
 	principalname2krb5_principal(&server,
 	    ap_req.ticket.sname, ap_req.ticket.realm);
 #else
-	_krb5_principalname2krb5_principal(&server,
+	_krb5_principalname2krb5_principal(context, &server,
 	    ap_req.ticket.sname, ap_req.ticket.realm);
 #endif
 
 	if (ap_req.ap_options.use_session_key && ac->keyblock == NULL) {
-		krb5_set_error_string(context, "krb5_rd_req: user to user "
-		    "auth without session key given");
 		ret = KRB5KRB_AP_ERR_NOKEY;
+		krb5_set_error_message(context, ret,
+		    "krb5_rd_req: user to user auth without session key given");
 		goto fail;
 	}
 
@@ -1009,6 +1014,13 @@
 	}
 
 	/* decrypt ticket */
+#if 1
+	ret = krb5_decrypt_ticket(context, &ap_req.ticket,
+	    ac->keyblock != NULL ? ac->keyblock : keyblock,
+	    &t->ticket, 0);
+	if (ret != 0)
+		goto fail;
+#else
 	{
 		krb5_data plain;
 		size_t len;
@@ -1030,6 +1042,7 @@
 		if (ret != 0)
 			goto fail;
 	}
+#endif
 
 	/* get keyblock from ticket */
 	if (ac->keyblock != NULL) {
@@ -1039,6 +1052,11 @@
 	krb5_copy_keyblock(context, &t->ticket.key, &ac->keyblock);
 
 	/* handle authenticator */
+#if 1
+	ret = krb5_auth_con_getauthenticator(context, ac, &ac->authenticator);
+	if (ret != 0)
+		goto fail;
+#else
 	{
 		krb5_data plain;
 		size_t len;
@@ -1059,6 +1077,7 @@
 		if (ret != 0)
 			goto fail;
 	}
+#endif
 	if (ac->authenticator->seq_number)
 		krb5_auth_con_setremoteseqnumber(context, ac,
 		    *ac->authenticator->seq_number);
