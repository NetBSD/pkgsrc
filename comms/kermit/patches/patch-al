$NetBSD: patch-al,v 1.3 2014/06/23 22:24:24 christos Exp $

--- ckuath.c.orig	2011-06-13 13:26:54.000000000 -0400
+++ ckuath.c	2014-06-23 18:20:26.000000000 -0400
@@ -117,19 +117,6 @@
 #include <time.h>
 #include <fcntl.h>
 #include <errno.h>
-#ifndef malloc
-#ifndef VMS
-#ifndef FREEBSD4
-#ifndef OpenBSD
-#ifdef MACOSX
-#include <sys/malloc.h>
-#else /* MACOSX */
-#include <malloc.h>
-#endif /* MACOSX */
-#endif /* OpenBSD */
-#endif /* FREEBSD4 */
-#endif /* VMS */
-#endif /* malloc */
 #ifdef OS2
 #include <io.h>
 #endif /* OS2 */
@@ -149,7 +136,9 @@
 #endif /* saveprintf */
 #else /* HEIMDAL */
 #include "krb5.h"
+#ifdef BETATEST
 #include "profile.h"
+#endif
 #include "com_err.h"
 #ifdef KRB5_GET_INIT_CREDS_OPT_TKT_LIFE
 #define KRB5_HAVE_GET_INIT_CREDS
@@ -417,7 +406,6 @@
 char des_outpkt[2*RLOG_BUFSIZ+4];    /* needs to be > largest write size */
 #ifdef KRB5
 krb5_data desinbuf,desoutbuf;
-krb5_encrypt_block eblock;             /* eblock for encrypt/decrypt */
 static krb5_data encivec_i[2], encivec_o[2];
 
 enum krb5_kcmd_proto {
@@ -3145,8 +3133,13 @@
             data.data = k4_session_key;
             data.length = 8;
 
-            code = krb5_c_decrypt(k5_context, &k4_krbkey, 0, 0,
-                                   &encdata, &data);
+            code = krb5_c_decrypt(k5_context,
+#ifdef HEIMDAL
+				  k4_krbkey,
+#else
+				  &k4_krbkey,
+#endif
+				  0, 0, &encdata, &data);
 
             krb5_free_keyblock_contents(k5_context, &random_key);
 
@@ -3162,8 +3155,13 @@
             data.data = k4_challenge;
             data.length = 8;
 
-            code = krb5_c_decrypt(k5_context, &k4_krbkey, 0, 0,
-                                   &encdata, &data);
+            code = krb5_c_decrypt(k5_context,
+#ifdef HEIMDAL
+				  k4_krbkey,
+#else
+				  &k4_krbkey,
+#endif
+				  0, 0, &encdata, &data);
 #else /* MIT_CURRENT */
             memset(k4_sched,0,sizeof(Schedule));
             ckhexdump("auth_send",cred.session,8);
@@ -3295,7 +3293,7 @@
     case AUTHTYPE_KERBEROS_V5:
         debug(F111,"auth_send KRB5","k5_auth.length",k5_auth.length);
         for ( i=0 ; i<k5_auth.length ; i++ ) {
-            if ( (char *)k5_auth.data[i] == IAC )
+            if ( ((char *)k5_auth.data)[i] == IAC )
                 iaccnt++;
         }
         if ( k5_auth.length + iaccnt + 10 < sizeof(buf) ) {
@@ -4250,8 +4248,13 @@
         kdata.data = k4_challenge;
         kdata.length = 8;
 
-        if (code = krb5_c_decrypt(k5_context, &k4_krbkey, 0, 0,
-                                   &encdata, &kdata)) {
+        if (code = krb5_c_decrypt(k5_context,
+#ifdef HEIMDAL
+				  k4_krbkey,
+#else
+				  &k4_krbkey,
+#endif
+				  0, 0, &encdata, &kdata)) {
             com_err("k4_auth_is", code, "while decrypting challenge");
             auth_finished(AUTH_REJECT);
             return AUTH_FAILURE;
@@ -4752,9 +4755,11 @@
         ap_opts |= AP_OPTS_MUTUAL_REQUIRED;
 
 #ifdef HEIMDAL
+#ifdef notdef
     r = krb5_auth_setkeytype(k5_context, auth_context, KEYTYPE_DES);
     if (r)
         com_err(NULL, r, "while setting auth keytype");
+#endif
     r = krb5_auth_con_setaddrs_from_fd(k5_context,auth_context, &ttyfd);
     if (r)
         com_err(NULL, r, "while setting auth addrs");
@@ -4924,7 +4929,6 @@
                     skey.data = k5_session_key->contents;
 #endif /* HEIMDAL */
                 } else {
-#ifdef HEIMDAL
                     switch ( k5_session_key->keytype ) {
                     case ETYPE_DES_CBC_CRC:
                     case ETYPE_DES_CBC_MD5:
@@ -4934,24 +4938,17 @@
                         break;
                     default:
                         skey.type = SK_GENERIC;
+#ifdef HEIMDAL
+                        skey.length = k5_session_key->keyvalue.length;
+#else /* HEIMDAL */
                         skey.length = k5_session_key->length;
+#endif /* HEIMDAL */
                         encrypt_dont_support(ENCTYPE_DES_CFB64);
                         encrypt_dont_support(ENCTYPE_DES_OFB64);
                     }
+#ifdef HEIMDAL
                     skey.data = k5_session_key->keyvalue.data;
 #else /* HEIMDAL */
-                    switch ( k5_session_key->enctype ) {
-                    case ENCTYPE_DES_CBC_CRC:
-                    case ENCTYPE_DES_CBC_MD5:
-                    case ENCTYPE_DES_CBC_MD4:
-                        skey.type = SK_DES;
-                        skey.length = 8;
-                    default:
-                        skey.type = SK_GENERIC;
-                        skey.length = k5_session_key->length;
-                        encrypt_dont_support(ENCTYPE_DES_CFB64);
-                        encrypt_dont_support(ENCTYPE_DES_OFB64);
-                    }
                     skey.data = k5_session_key->contents;
 #endif /* HEIMDAL */
                 }
@@ -5038,7 +5035,6 @@
                     skey.data = k5_session_key->contents;
 #endif /* HEIMDAL */
                 } else {
-#ifdef HEIMDAL
                     switch ( k5_session_key->keytype ) {
                     case ETYPE_DES_CBC_CRC:
                     case ETYPE_DES_CBC_MD5:
@@ -5047,21 +5043,15 @@
                         skey.length = 8;
                     default:
                         skey.type = SK_GENERIC;
+#ifdef HEIMDAL
+                        skey.length = k5_session_key->keyvalue.length;
+#else /* HEIMDAL */
                         skey.length = k5_session_key->length;
+#endif /* HEIMDAL */
                     }
+#ifdef HEIMDAL
                     skey.data = k5_session_key->keyvalue.data;
 #else /* HEIMDAL */
-                    switch ( k5_session_key->enctype ) {
-                    case ENCTYPE_DES_CBC_CRC:
-                    case ENCTYPE_DES_CBC_MD5:
-                    case ENCTYPE_DES_CBC_MD4:
-                        skey.type = SK_DES;
-                        skey.length = 8;
-                        break;
-                    default:
-                        skey.type = SK_GENERIC;
-                        skey.length = k5_session_key->length;
-                    }
                     skey.data = k5_session_key->contents;
 #endif /* HEIMDAL */
                 }
@@ -5138,7 +5128,11 @@
             }
             if ( msg.length == 24 && !memcmp(msg.data,tls_verify,24) )
                  krb5_tls_verified = 1;
+#ifdef HEIMDAL
+            krb5_data_free(&msg);
+#else /* HEIMDAL */
             krb5_free_data_contents(k5_context,&msg);
+#endif /* HEIMDAL */
             if (krb5_tls_verified)
                 return(AUTH_SUCCESS);
         }
@@ -5166,7 +5160,7 @@
     krb5_context context;
     krb5_auth_context auth_context;
     krb5_data *inbuf;
-    krb5_const_principal client;
+    krb5_principal client;
 {
     krb5_creds ** creds=NULL;
     krb5_error_code retval;
@@ -5197,7 +5191,7 @@
     if ((retval = krb5_cc_initialize(context, ccache, client)))
         return(retval);
 
-    if ((retval = krb5_rd_cred(context, auth_context, ccache, inbuf)))
+    if ((retval = krb5_rd_cred2(context, auth_context, ccache, inbuf)))
         return(retval);
 #else /* HEIMDAL */
     if ((retval = krb5_rd_cred(context, auth_context, inbuf, &creds, NULL)))
@@ -5472,17 +5466,17 @@
                 goto errout;
             }
             SendK5AuthSB(KRB5_TLS_VERIFY, msg.data, msg.length);
+#ifdef HEIMDAL
+            krb5_data_free(&msg);
+#else
             krb5_free_data_contents(k5_context,&msg);
+#endif
         }
 #endif /* CK_SSL */
         if ((how & AUTH_HOW_MASK) == AUTH_HOW_MUTUAL) {
             /* do ap_rep stuff here */
             if ((r = krb5_mk_rep(k5_context,
-#ifdef HEIMDAL
-                                  &auth_context,
-#else /* HEIMDAL */
                                   auth_context,
-#endif /* HEIMDAL */
                                   &outbuf))) {
                 debug(F111,"k5_auth_is","krb5_mk_rep",r);
                 (void) ckstrncpy(errbuf, "Make reply failed: ",sizeof(errbuf));
@@ -5503,7 +5497,7 @@
             {
                 szUserNameAuthenticated[0] = '\0';
             } else {
-                ckstrncpy(szUserNameAuthenticated,UIDBUFLEN,name);
+                ckstrncpy(szUserNameAuthenticated,name,UIDBUFLEN);
                 free(name);
             }
         }
@@ -9687,6 +9681,7 @@
     return(-1);
 }
 
+int
 #ifdef CK_ANSIC
 ck_krb4_destroy(struct krb_op_data * op)
 #else
@@ -11228,7 +11223,12 @@
 
     use_ivecs = 1;
 
-    if (status = krb5_c_block_size(k5_context, k5_session_key->enctype,
+    if (status = krb5_c_block_size(k5_context,
+#ifdef HEIMDAL
+    k5_session_key->keytype,
+#else
+    k5_session_key->enctype,
+#endif
                                    &blocksize)) {
         /* XXX what do I do? */
         printf("fatal kerberos 5 crypto library error\n");
@@ -11309,8 +11309,7 @@
         krb5_ap_rep_enc_part *rep_ret = NULL;
         krb5_data outbuf;
         int rc;
-        krb5_int32 seqno=0;
-        krb5_int32 server_seqno=0;
+        int server_seqno=0;
         char ** realmlist=NULL;
         int buflen;
         char tgt[256];
@@ -11388,7 +11387,11 @@
         }
 
         if (krb5_rlog_ver == KCMD_OLD_PROTOCOL)
+#ifdef HEIMDAL
+            get_cred->session.keytype=ETYPE_DES_CBC_CRC;
+#else
             get_cred->keyblock.enctype=ENCTYPE_DES_CBC_CRC;
+#endif
 
         /* Get ticket from credentials cache or kdc */
         status = krb5_get_credentials(k5_context,
@@ -11429,10 +11432,11 @@
             krb5_boolean is_des;
 
             if (status = krb5_c_enctype_compare( k5_context,
-                                                 ENCTYPE_DES_CBC_CRC,
 #ifdef HEIMDAL
+						 ETYPE_DES_CBC_CRC,
                                                  ret_cred->session.keytype,
 #else /* HEIMDAL */
+                                                 ENCTYPE_DES_CBC_CRC,
                                                  ret_cred->keyblock.enctype,
 #endif /* HEIMDAL */
                                                  &is_des)) {
@@ -11482,7 +11486,11 @@
                                &rep_ret,
                                NULL
                                );
+#ifdef HEIMDAL
+        krb5_data_free(&cksumdat);
+#else
         krb5_free_data_contents(k5_context,&cksumdat);
+#endif
 
         if (status) {
             if ( !quiet )
@@ -11490,12 +11498,17 @@
                         error_message(status));
             if (error) {
                 if ( !quiet ) {
-                    printf("Server returned error code %d (%s)\r\n",
-                        error->error,
-                        error_message(ERROR_TABLE_BASE_krb5 + error->error));
-                    if (error->text.length) {
-                        printf("Error text sent from server: %s\r\n",
-                                error->text.data);
+#ifdef HEIMDAL
+		    int xerror = error->error_code;
+		    char *xtext = *error->e_text;
+#else
+		    int xerror = error->error;
+		    char *xtext = error->text.length ? error->text.data : NULL;
+#endif
+                    printf("Server returned error code %d (%s)\r\n", xerror,
+                        error_message(ERROR_TABLE_BASE_krb5 + xerror));
+                    if (xtext) {
+                        printf("Error text sent from server: %s\r\n", xtext);
                     }
                 }
                 krb5_free_error(k5_context, error);
@@ -11505,7 +11518,11 @@
         }
 
         if (rep_ret) {
+#ifdef HEIMDAL
+            server_seqno = *rep_ret->seq_number;
+#else
             server_seqno = rep_ret->seq_number;
+#endif
             krb5_free_ap_rep_enc_part(k5_context, rep_ret);
         }
 
@@ -11834,7 +11851,11 @@
     rd_len = (rd_len << 8) | c;
 
     if (status = krb5_c_encrypt_length(k5_context, 
+#ifdef HEIMDAL
+                                    k5_session_key->keytype,
+#else
                                     k5_session_key->enctype,
+#endif
                                     use_ivecs ? rd_len + 4 : rd_len,
 				    (size_t *)&net_len)) {
         errno = status;
@@ -11865,9 +11886,15 @@
     plain.length = sizeof(storage);
     plain.data = storage;
 
-    if ( status = krb5_c_decrypt(k5_context, k5_session_key, KCMD_KEYUSAGE,
+    if ( status = krb5_c_decrypt(k5_context,
+#ifdef HEIMDAL
+				 *k5_session_key,
+#else
+				 k5_session_key,
+#endif
+				 KCMD_KEYUSAGE,
                                  use_ivecs ? encivec_i + secondary : 0,
-                                  &cipher,&plain) ) {
+                                 &cipher,&plain) ) {
         /* probably out of sync */
         printf("Cannot decrypt data from network: %s\r\n",
                  error_message(status));
@@ -12759,8 +12786,8 @@
 
 static int
 binaryEqual (a, b, len)
-register char   *a, *b;
-register int    len;
+char   *a, *b;
+int    len;
 {
     while (len--)
         if (*a++ != *b++)
