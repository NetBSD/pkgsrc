$NetBSD: patch-bin_afppasswd_afppasswd.c,v 1.1 2014/06/11 11:03:57 hauke Exp $

--- bin/afppasswd/afppasswd.c.orig	2013-04-09 12:56:17.000000000 +0000
+++ bin/afppasswd/afppasswd.c
@@ -35,7 +35,7 @@
 #include <pwd.h>
 #include <arpa/inet.h>
 
-#include <des.h>
+#include <openssl/des.h>
 
 #ifdef USE_CRACKLIB
 #include <crack.h>
@@ -65,7 +65,7 @@ static char buf[MAXPATHLEN + 1];
 static void convert_passwd(char *buf, char *newpwd, const int keyfd)
 {
   uint8_t key[HEXPASSWDLEN];
-  Key_schedule schedule;
+  DES_key_schedule schedule;
   unsigned int i, j;
 
   if (!newpwd) {
@@ -84,14 +84,14 @@ static void convert_passwd(char *buf, ch
       key[j] = (unhex(key[i]) << 4) | unhex(key[i + 1]);
     if (j <= DES_KEY_SZ)
       memset(key + j, 0, sizeof(key) - j);
-    key_sched((C_Block *) key, schedule);
+    DES_key_sched((DES_cblock *) key, &schedule);
     memset(key, 0, sizeof(key));   
     if (newpwd) {
-	ecb_encrypt((C_Block *) newpwd, (C_Block *) newpwd, schedule,
+	DES_ecb_encrypt((DES_cblock *) newpwd, (DES_cblock *) newpwd, &schedule,
 		    DES_ENCRYPT);
     } else {
       /* decrypt the password */
-      ecb_encrypt((C_Block *) buf, (C_Block *) buf, schedule, DES_DECRYPT);
+      DES_ecb_encrypt((DES_cblock *) buf, (DES_cblock *) buf, &schedule, DES_DECRYPT);
     }
     memset(&schedule, 0, sizeof(schedule));      
   }
