$NetBSD: patch-crypto_hash_hmac.c,v 1.1 2016/09/26 13:20:41 maya Exp $

avoid conflict with builtin hmac on netbsd 7.99.x

--- crypto/hash/hmac.c.orig	2016-09-21 15:34:12.042157000 +0000
+++ crypto/hash/hmac.c
@@ -55,7 +55,7 @@ debug_module_t mod_hmac = {
 
 err_status_t
 hmac_alloc(auth_t **a, int key_len, int out_len) {
-  extern auth_type_t hmac;
+  extern auth_type_t local_hmac;
   uint8_t *pointer;
 
   debug_print(mod_hmac, "allocating auth func with key length %d", key_len);
@@ -79,21 +79,21 @@ hmac_alloc(auth_t **a, int key_len, int 
 
   /* set pointers */
   *a = (auth_t *)pointer;
-  (*a)->type = &hmac;
+  (*a)->type = &local_hmac;
   (*a)->state = pointer + sizeof(auth_t);  
   (*a)->out_len = out_len;
   (*a)->key_len = key_len;
   (*a)->prefix_len = 0;
 
   /* increment global count of all hmac uses */
-  hmac.ref_count++;
+  local_hmac.ref_count++;
 
   return err_status_ok;
 }
 
 err_status_t
 hmac_dealloc(auth_t *a) {
-  extern auth_type_t hmac;
+  extern auth_type_t local_hmac;
   
   /* zeroize entire state*/
   octet_string_set_to_zero((uint8_t *)a, 
@@ -103,7 +103,7 @@ hmac_dealloc(auth_t *a) {
   crypto_free(a);
   
   /* decrement global count of all hmac uses */
-  hmac.ref_count--;
+  local_hmac.ref_count--;
 
   return err_status_ok;
 }
@@ -252,7 +252,7 @@ char hmac_description[] = "hmac sha-1 au
  */
 
 auth_type_t
-hmac  = {
+local_hmac  = {
   (auth_alloc_func)      hmac_alloc,
   (auth_dealloc_func)    hmac_dealloc,
   (auth_init_func)       hmac_init,
