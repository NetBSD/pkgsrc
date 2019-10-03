$NetBSD: patch-lfd__encrypt.c,v 1.1 2019/10/03 12:11:43 kardel Exp $

Adjust to compile also with openssl>=1.1

--- lfd_encrypt.c.orig	2019-08-23 08:37:39.608971418 +0000
+++ lfd_encrypt.c
@@ -77,6 +77,11 @@ struct vtun_host *phost;
 
 extern int send_a_packet;
 
+static int send_msg(int len, char *in, char **out);
+static int send_ib_mesg(int *len, char **in);
+static int recv_msg(int len, char *in, char **out);
+static int recv_ib_mesg(int *len, char **in);
+
 /* out of sync packet threshold before forcing a re-init */ 
 #define MAX_GIBBERISH	10
 #define MIN_GIBBERISH   1
@@ -95,11 +100,11 @@ unsigned long sequence_num;
 char * pkey;
 char * iv_buf;
 
-EVP_CIPHER_CTX ctx_enc;	/* encrypt */
-EVP_CIPHER_CTX ctx_dec;	/* decrypt */
+EVP_CIPHER_CTX *ctx_enc = NULL;	/* encrypt */
+EVP_CIPHER_CTX *ctx_dec = NULL;	/* decrypt */
 
-EVP_CIPHER_CTX ctx_enc_ecb;	/* sideband ecb encrypt */
-EVP_CIPHER_CTX ctx_dec_ecb;	/* sideband ecb decrypt */
+EVP_CIPHER_CTX *ctx_enc_ecb = NULL;	/* sideband ecb encrypt */
+EVP_CIPHER_CTX *ctx_dec_ecb = NULL;	/* sideband ecb decrypt */
 
 int prep_key(char **key, int size, struct vtun_host *host)
 {
@@ -154,6 +159,14 @@ int alloc_encrypt(struct vtun_host *host
    enc_init_first_time = 1;   
    dec_init_first_time = 1;   
 
+   if (ctx_enc == NULL) {
+	ctx_enc = EVP_CIPHER_CTX_new();	/* encrypt */
+	ctx_dec = EVP_CIPHER_CTX_new();	/* decrypt */
+
+	ctx_enc_ecb = EVP_CIPHER_CTX_new();	/* sideband ecb encrypt */
+	ctx_dec_ecb = EVP_CIPHER_CTX_new();	/* sideband ecb decrypt */
+   }
+
    if( !(enc_buf = lfd_alloc(ENC_BUF_SIZE)) ){
       vtun_syslog(LOG_ERR,"Can't allocate buffer for encryptor");
       return -1;
@@ -177,15 +190,15 @@ int alloc_encrypt(struct vtun_host *host
          keysize = 32;
          sb_init = 1;
          cipher_type = EVP_aes_256_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
       
       case VTUN_ENC_AES256ECB:
          blocksize = 16;
          keysize = 32;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_aes_256_ecb();
          strcpy(cipher_name,"AES-256-ECB");
       break;      
@@ -196,14 +209,14 @@ int alloc_encrypt(struct vtun_host *host
          keysize = 16;
          sb_init=1;
          cipher_type = EVP_aes_128_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
       case VTUN_ENC_AES128ECB:
          blocksize = 16;
          keysize = 16;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_aes_128_ecb();
          strcpy(cipher_name,"AES-128-ECB");
       break;
@@ -216,16 +229,16 @@ int alloc_encrypt(struct vtun_host *host
          var_key = 1;
          sb_init = 1;
          cipher_type = EVP_bf_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
 
       case VTUN_ENC_BF256ECB:
          blocksize = 8;
          keysize = 32;
          var_key = 1;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_bf_ecb();
          strcpy(cipher_name,"Blowfish-256-ECB");
       break;
@@ -238,16 +251,16 @@ int alloc_encrypt(struct vtun_host *host
          var_key = 1;
          sb_init = 1;
          cipher_type = EVP_bf_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
       case VTUN_ENC_BF128ECB: /* blowfish 128 ecb is the default */
       default:
          blocksize = 8;
          keysize = 16;
          var_key = 1;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_bf_ecb();
          strcpy(cipher_name,"Blowfish-128-ECB");
       break;
@@ -289,10 +302,10 @@ int free_encrypt()
    lfd_free(enc_buf); enc_buf = NULL;
    lfd_free(dec_buf); dec_buf = NULL;
 
-   EVP_CIPHER_CTX_cleanup(&ctx_enc);
-   EVP_CIPHER_CTX_cleanup(&ctx_dec);
-   EVP_CIPHER_CTX_cleanup(&ctx_enc_ecb);
-   EVP_CIPHER_CTX_cleanup(&ctx_dec_ecb);
+   EVP_CIPHER_CTX_cleanup(ctx_enc);
+   EVP_CIPHER_CTX_cleanup(ctx_dec);
+   EVP_CIPHER_CTX_cleanup(ctx_enc_ecb);
+   EVP_CIPHER_CTX_cleanup(ctx_dec_ecb);
 
    return 0;
 }
@@ -318,7 +331,7 @@ int encrypt_buf(int len, char *in, char 
    outlen=len+pad;
    if (pad == blocksize)
       RAND_bytes(in_ptr+len, blocksize-1);
-   EVP_EncryptUpdate(&ctx_enc, out_ptr, &outlen, in_ptr, len+pad);
+   EVP_EncryptUpdate(ctx_enc, out_ptr, &outlen, in_ptr, len+pad);
    *out = enc_buf;
 
    sequence_num++;
@@ -338,7 +351,7 @@ int decrypt_buf(int len, char *in, char 
 
    outlen=len;
    if (!len) return 0;
-   EVP_DecryptUpdate(&ctx_dec, out_ptr, &outlen, in_ptr, len);
+   EVP_DecryptUpdate(ctx_dec, out_ptr, &outlen, in_ptr, len);
    recv_ib_mesg(&outlen, &out_ptr);
    if (!outlen) return 0;
    tmp_ptr = out_ptr + outlen; tmp_ptr--;
@@ -426,13 +439,13 @@ int cipher_enc_init(char * iv)
       break;
    } /* switch(cipher) */
 
-   EVP_CIPHER_CTX_init(&ctx_enc);
-   EVP_EncryptInit_ex(&ctx_enc, cipher_type, NULL, NULL, NULL);
+   EVP_CIPHER_CTX_init(ctx_enc);
+   EVP_EncryptInit_ex(ctx_enc, cipher_type, NULL, NULL, NULL);
    if (var_key)
-      EVP_CIPHER_CTX_set_key_length(&ctx_enc, keysize);
-   EVP_EncryptInit_ex(&ctx_enc, NULL, NULL, pkey, NULL);
-   EVP_EncryptInit_ex(&ctx_enc, NULL, NULL, NULL, iv);
-   EVP_CIPHER_CTX_set_padding(&ctx_enc, 0);
+      EVP_CIPHER_CTX_set_key_length(ctx_enc, keysize);
+   EVP_EncryptInit_ex(ctx_enc, NULL, NULL, pkey, NULL);
+   EVP_EncryptInit_ex(ctx_enc, NULL, NULL, NULL, iv);
+   EVP_CIPHER_CTX_set_padding(ctx_enc, 0);
    if (enc_init_first_time)
    {
       sprintf(tmpstr,"%s encryption initialized", cipher_name);
@@ -516,13 +529,13 @@ int cipher_dec_init(char * iv)
       break;
    } /* switch(cipher) */
 
-   EVP_CIPHER_CTX_init(&ctx_dec);
-   EVP_DecryptInit_ex(&ctx_dec, cipher_type, NULL, NULL, NULL);
+   EVP_CIPHER_CTX_init(ctx_dec);
+   EVP_DecryptInit_ex(ctx_dec, cipher_type, NULL, NULL, NULL);
    if (var_key)
-      EVP_CIPHER_CTX_set_key_length(&ctx_dec, keysize);
-   EVP_DecryptInit_ex(&ctx_dec, NULL, NULL, pkey, NULL);
-   EVP_DecryptInit_ex(&ctx_dec, NULL, NULL, NULL, iv);
-   EVP_CIPHER_CTX_set_padding(&ctx_dec, 0);
+      EVP_CIPHER_CTX_set_key_length(ctx_dec, keysize);
+   EVP_DecryptInit_ex(ctx_dec, NULL, NULL, pkey, NULL);
+   EVP_DecryptInit_ex(ctx_dec, NULL, NULL, NULL, iv);
+   EVP_CIPHER_CTX_set_padding(ctx_dec, 0);
    if (dec_init_first_time)
    {
       sprintf(tmpstr,"%s decryption initialized", cipher_name);
@@ -532,7 +545,7 @@ int cipher_dec_init(char * iv)
    return 0;
 }
 
-int send_msg(int len, char *in, char **out)
+static int send_msg(int len, char *in, char **out)
 {
    char * iv; char * in_ptr;
    int outlen;
@@ -554,7 +567,7 @@ int send_msg(int len, char *in, char **o
 
          in_ptr = in - blocksize*2;
          outlen = blocksize*2;
-         EVP_EncryptUpdate(&ctx_enc_ecb, in_ptr, 
+         EVP_EncryptUpdate(ctx_enc_ecb, in_ptr, 
             &outlen, in_ptr, blocksize*2);
          *out = in_ptr;
          len = outlen;
@@ -570,7 +583,7 @@ int send_msg(int len, char *in, char **o
    return len;
 }
 
-int recv_msg(int len, char *in, char **out)
+static int recv_msg(int len, char *in, char **out)
 {
    char * iv; char * in_ptr;
    int outlen;
@@ -581,7 +594,7 @@ int recv_msg(int len, char *in, char **o
          in_ptr = in;
          iv = malloc(blocksize);
          outlen = blocksize*2;
-         EVP_DecryptUpdate(&ctx_dec_ecb, in_ptr, &outlen, in_ptr, blocksize*2);
+         EVP_DecryptUpdate(ctx_dec_ecb, in_ptr, &outlen, in_ptr, blocksize*2);
          
          if ( !strncmp(in_ptr, "ivec", 4) )
          {
@@ -624,7 +637,7 @@ int recv_msg(int len, char *in, char **o
                if (cipher_enc_state != CIPHER_INIT)
                {
                   cipher_enc_state = CIPHER_INIT;
-                  EVP_CIPHER_CTX_cleanup(&ctx_enc);
+                  EVP_CIPHER_CTX_cleanup(ctx_enc);
 #ifdef LFD_ENCRYPT_DEBUG
                   vtun_syslog(LOG_INFO, 
                      "Forcing local encryptor re-init");
@@ -645,7 +658,7 @@ int recv_msg(int len, char *in, char **o
 }
 
 /* Send In-Band Message */
-int send_ib_mesg(int *len, char **in)
+static int send_ib_mesg(int *len, char **in)
 {
    char *in_ptr = *in;
 
@@ -684,7 +697,7 @@ int send_ib_mesg(int *len, char **in)
 }
 
 /* Receive In-Band Message */
-int recv_ib_mesg(int *len, char **in)
+static int recv_ib_mesg(int *len, char **in)
 {
    char *in_ptr = *in;
 
@@ -705,7 +718,7 @@ int recv_ib_mesg(int *len, char **in)
          if (cipher_enc_state != CIPHER_INIT)
          {
             cipher_enc_state = CIPHER_INIT;
-            EVP_CIPHER_CTX_cleanup(&ctx_enc);
+            EVP_CIPHER_CTX_cleanup(ctx_enc);
          }
 #ifdef LFD_ENCRYPT_DEBUG
          vtun_syslog(LOG_INFO, "Remote requests encryptor re-init");
@@ -719,7 +732,7 @@ int recv_ib_mesg(int *len, char **in)
              cipher_enc_state != CIPHER_REQ_INIT &&
              cipher_enc_state != CIPHER_INIT)
          {
-            EVP_CIPHER_CTX_cleanup (&ctx_dec);
+            EVP_CIPHER_CTX_cleanup (ctx_dec);
             cipher_dec_state = CIPHER_INIT;
             cipher_enc_state = CIPHER_REQ_INIT;
          }
