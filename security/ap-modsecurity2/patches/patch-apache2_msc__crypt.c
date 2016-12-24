$NetBSD: patch-apache2_msc__crypt.c,v 1.1 2016/12/24 10:16:50 joerg Exp $

Avoid conflict with NetBSD's hmac(3).

--- apache2/msc_crypt.c.orig	2016-12-24 09:55:14.605925316 +0000
+++ apache2/msc_crypt.c
@@ -182,7 +182,7 @@ char *getkey(apr_pool_t *mp) {
  *
  * \retval hex_digest The MAC
  */
-char *hmac(modsec_rec *msr, const char *key, int key_len,
+char *mschmac(modsec_rec *msr, const char *key, int key_len,
         unsigned char *msg, int msglen) {
     apr_sha1_ctx_t ctx;
     unsigned char digest[APR_SHA1_DIGESTSIZE];
@@ -1245,7 +1245,7 @@ char *do_hash_link(modsec_rec *msr, char
                 }
 
             if(msr->txcfg->crypto_key_add == HASH_KEYONLY)
-                hash_value =  hmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                hash_value =  mschmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
 
             if(msr->txcfg->crypto_key_add == HASH_SESSIONID)  {
                 if(msr->sessionid == NULL || strlen(msr->sessionid) == 0)   {
@@ -1257,13 +1257,13 @@ char *do_hash_link(modsec_rec *msr, char
                     if (msr->txcfg->debuglog_level >= 4)
                         msr_log(msr, 4, "Session id is empty. Using REMOTE_IP");
                     msr->txcfg->crypto_key_len = strlen(new_pwd);
-                    hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                    hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
                 } else {
                     const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->sessionid);
                     if (msr->txcfg->debuglog_level >= 4)
                         msr_log(msr, 4, "Using session id [%s]", msr->sessionid);
                     msr->txcfg->crypto_key_len = strlen(new_pwd);
-                    hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                    hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
                 }
             }
 
@@ -1274,7 +1274,7 @@ char *do_hash_link(modsec_rec *msr, char
                 const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->r->connection->remote_ip);
 #endif
                 msr->txcfg->crypto_key_len = strlen(new_pwd);
-                hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
             }
         } else  {
             return NULL;
@@ -1288,7 +1288,7 @@ char *do_hash_link(modsec_rec *msr, char
                 }
 
                 if(msr->txcfg->crypto_key_add == HASH_KEYONLY)
-                    hash_value =  hmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                    hash_value =  mschmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
 
                 if(msr->txcfg->crypto_key_add == HASH_SESSIONID)  {
                     if(msr->sessionid == NULL || strlen(msr->sessionid) == 0)   {
@@ -1300,13 +1300,13 @@ char *do_hash_link(modsec_rec *msr, char
                         if (msr->txcfg->debuglog_level >= 4)
                             msr_log(msr, 4, "Session id is empty. Using REMOTE_IP");
                         msr->txcfg->crypto_key_len = strlen(new_pwd);
-                        hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                        hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
                     } else {
                         const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->sessionid);
                         if (msr->txcfg->debuglog_level >= 4)
                             msr_log(msr, 4, "Using session id [%s]", msr->sessionid);
                         msr->txcfg->crypto_key_len = strlen(new_pwd);
-                        hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                        hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
                     }
                 }
 
@@ -1317,7 +1317,7 @@ char *do_hash_link(modsec_rec *msr, char
                     const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->r->connection->remote_ip);
 #endif
                     msr->txcfg->crypto_key_len = strlen(new_pwd);
-                    hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
+                    hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) path_chunk+1, strlen((char*)path_chunk)-1);
                 }
             } else  {
                 return NULL;
@@ -1329,7 +1329,7 @@ char *do_hash_link(modsec_rec *msr, char
                 }
 
             if(msr->txcfg->crypto_key_add == HASH_KEYONLY)
-                hash_value = hmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
+                hash_value = mschmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
 
             if(msr->txcfg->crypto_key_add == HASH_SESSIONID)  {
                 if(msr->sessionid == NULL || strlen(msr->sessionid) == 0)   {
@@ -1341,13 +1341,13 @@ char *do_hash_link(modsec_rec *msr, char
                     if (msr->txcfg->debuglog_level >= 4)
                         msr_log(msr, 4, "Session id is empty. Using REMOTE_IP");
                     msr->txcfg->crypto_key_len = strlen(new_pwd);
-                    hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
+                    hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
                 } else  {
                     const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->sessionid);
                     if (msr->txcfg->debuglog_level >= 4)
                         msr_log(msr, 4, "Using session id [%s]", msr->sessionid);
                     msr->txcfg->crypto_key_len = strlen(new_pwd);
-                    hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
+                    hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
                 }
             }
 
@@ -1358,7 +1358,7 @@ char *do_hash_link(modsec_rec *msr, char
                 const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->r->connection->remote_ip);
 #endif
                 msr->txcfg->crypto_key_len = strlen(new_pwd);
-                hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
+                hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) link+1, strlen((char*)link)-1);
             }
 
         }
@@ -1383,7 +1383,7 @@ char *do_hash_link(modsec_rec *msr, char
                 }
 
             if(msr->txcfg->crypto_key_add == HASH_KEYONLY)
-                hash_value = hmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
+                hash_value = mschmac(msr, msr->txcfg->crypto_key, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
 
             if(msr->txcfg->crypto_key_add == HASH_SESSIONID)  {
                 if(msr->sessionid == NULL || strlen(msr->sessionid) == 0)   {
@@ -1395,13 +1395,13 @@ char *do_hash_link(modsec_rec *msr, char
                     if (msr->txcfg->debuglog_level >= 4)
                         msr_log(msr, 4, "Session id is empty. Using REMOTE_IP");
                     msr->txcfg->crypto_key_len = strlen(new_pwd);
-                    hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
+                    hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
                 } else {
                     const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->sessionid);
                     if (msr->txcfg->debuglog_level >= 4)
                         msr_log(msr, 4, "Using session id [%s]", msr->sessionid);
                     msr->txcfg->crypto_key_len = strlen(new_pwd);
-                    hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
+                    hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
                 }
             }
 
@@ -1412,7 +1412,7 @@ char *do_hash_link(modsec_rec *msr, char
                 const char *new_pwd = apr_psprintf(msr->mp,"%s%s", msr->txcfg->crypto_key, msr->r->connection->remote_ip);
 #endif
                 msr->txcfg->crypto_key_len = strlen(new_pwd);
-                hash_value = hmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
+                hash_value = mschmac(msr, new_pwd, msr->txcfg->crypto_key_len, (unsigned char *) relative_link, strlen((char*)relative_link));
             }
 
         link = relative_uri;
