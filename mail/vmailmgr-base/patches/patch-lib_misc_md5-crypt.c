$NetBSD: patch-lib_misc_md5-crypt.c,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Provide modern prototypes.

--- lib/misc/md5-crypt.c.orig	2024-02-22 18:33:20.895490263 +0000
+++ lib/misc/md5-crypt.c
@@ -53,11 +53,7 @@ extern char *md5_crypt __P ((const char
 /* This entry point is equivalent to the `crypt' function in Unix
    libcs.  */
 char *
-md5_crypt_r (key, salt, buffer, buflen)
-     const char *key;
-     const char *salt;
-     char *buffer;
-     int buflen;
+md5_crypt_r (const char *key, const char *salt, char *buffer, int buflen)
 {
   unsigned char alt_result[16];
   struct md5_ctx ctx;
@@ -213,9 +209,7 @@ md5_crypt_r (key, salt, buffer, buflen)
 
 
 char *
-md5_crypt (key, salt)
-     const char *key;
-     const char *salt;
+md5_crypt (const char *key, const char *salt)
 {
   /* We don't want to have an arbitrary limit in the size of the
      password.  We can compute the size of the result in advance and
