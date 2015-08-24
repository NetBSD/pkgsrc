$NetBSD: patch-etc_uams_uams__randnum.c,v 1.1.10.1 2015/08/24 19:59:57 tron Exp $

--- etc/uams/uams_randnum.c.orig	2014-01-04 16:42:35.000000000 +0100
+++ etc/uams/uams_randnum.c	2015-08-10 16:38:08.000000000 +0200
@@ -24,18 +24,18 @@
 #include <atalk/afp.h>
 #include <atalk/uam.h>
 
 
-#include <des.h>
+#include <openssl/des.h>
 
 #ifdef USE_CRACKLIB
 #include <crack.h>
 #endif /* USE_CRACKLIB */
 
 #define PASSWDLEN 8
 
-static C_Block		seskey;
-static Key_schedule	seskeysched;
+static DES_cblock	seskey;
+static DES_key_schedule	seskeysched;
 static struct passwd	*randpwd;
 static uint8_t         randbuf[8];
 
 /* hash to a 16-bit number. this will generate completely harmless 
@@ -123,9 +123,9 @@
 		     const int set)
 {
   uint8_t key[DES_KEY_SZ*2];
   char buf[MAXPATHLEN + 1], *p;
-  Key_schedule	schedule;
+  DES_key_schedule	schedule;
   FILE *fp;
   unsigned int i, j;
   int keyfd = -1, err = 0;
   off_t pos;
@@ -180,19 +180,20 @@
       for (i = j = 0; i < strlen((char *) key); i += 2, j++)
 	key[j] = (unhex(key[i]) << 4) | unhex(key[i + 1]);
       if (j <= DES_KEY_SZ)
 	memset(key + j, 0, sizeof(key) - j);
-      key_sched((C_Block *) key, schedule);
+      DES_key_sched((DES_cblock *) key, &schedule);
       memset(key, 0, sizeof(key));
 
       if (set) {
 	/* NOTE: this takes advantage of the fact that passwd doesn't
 	 *       get used after this call if it's being set. */
-	ecb_encrypt((C_Block *) passwd, (C_Block *) passwd, schedule,
-		    DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock *) passwd, (DES_cblock *) passwd,
+			&schedule, DES_ENCRYPT);
       } else {
 	/* decrypt the password */
-	ecb_encrypt((C_Block *) p, (C_Block *) p, schedule, DES_DECRYPT);
+	DES_ecb_encrypt((DES_cblock *) p, (DES_cblock *) p,
+			&schedule, DES_DECRYPT);
       }
       memset(&schedule, 0, sizeof(schedule));
   }
 
@@ -339,12 +340,12 @@
   ibuf += sizeof(sessid);
 
   /* encrypt. this saves a little space by using the fact that
    * des can encrypt in-place without side-effects. */
-  key_sched((C_Block *) seskey, seskeysched);
+  DES_key_sched((DES_cblock *) seskey, &seskeysched);
   memset(seskey, 0, sizeof(seskey));
-  ecb_encrypt((C_Block *) randbuf, (C_Block *) randbuf,
-	       seskeysched, DES_ENCRYPT);
+  DES_ecb_encrypt((DES_cblock *) randbuf, (DES_cblock *) randbuf,
+	       &seskeysched, DES_ENCRYPT);
   memset(&seskeysched, 0, sizeof(seskeysched));
 
   /* test against what the client sent */
   if (memcmp( randbuf, ibuf, sizeof(randbuf) )) { /* != */
@@ -383,12 +384,12 @@
   for (i = 0; i < sizeof(seskey); i++)
     seskey[i] <<= 1;
 
   /* encrypt randbuf */
-  key_sched((C_Block *) seskey, seskeysched);
+  DES_key_sched((DES_cblock *) seskey, &seskeysched);
   memset(seskey, 0, sizeof(seskey));
-  ecb_encrypt( (C_Block *) randbuf, (C_Block *) randbuf,
-	       seskeysched, DES_ENCRYPT);
+  DES_ecb_encrypt( (DES_cblock *) randbuf, (DES_cblock *) randbuf,
+	       &seskeysched, DES_ENCRYPT);
 
   /* test against client's reply */
   if (memcmp(randbuf, ibuf, sizeof(randbuf))) { /* != */
     memset(randbuf, 0, sizeof(randbuf));
@@ -398,10 +399,10 @@
   ibuf += sizeof(randbuf);
   memset(randbuf, 0, sizeof(randbuf));
 
   /* encrypt client's challenge and send back */
-  ecb_encrypt( (C_Block *) ibuf, (C_Block *) rbuf,
-	       seskeysched, DES_ENCRYPT);
+  DES_ecb_encrypt( (DES_cblock *) ibuf, (DES_cblock *) rbuf,
+	       &seskeysched, DES_ENCRYPT);
   memset(&seskeysched, 0, sizeof(seskeysched));
   *rbuflen = sizeof(randbuf);
   
   *uam_pwd = randpwd;
@@ -434,17 +435,19 @@
 			sizeof(seskey), 0)) != AFP_OK)
       return err;
 
     /* use old passwd to decrypt new passwd */
-    key_sched((C_Block *) seskey, seskeysched);
+    DES_key_sched((DES_cblock *) seskey, &seskeysched);
     ibuf += PASSWDLEN; /* new passwd */
     ibuf[PASSWDLEN] = '\0';
-    ecb_encrypt( (C_Block *) ibuf, (C_Block *) ibuf, seskeysched, DES_DECRYPT);
+    DES_ecb_encrypt( (DES_cblock *) ibuf, (DES_cblock *) ibuf,
+		     &seskeysched, DES_DECRYPT);
 
     /* now use new passwd to decrypt old passwd */
-    key_sched((C_Block *) ibuf, seskeysched);
+    DES_key_sched((DES_cblock *) ibuf, &seskeysched);
     ibuf -= PASSWDLEN; /* old passwd */
-    ecb_encrypt((C_Block *) ibuf, (C_Block *) ibuf, seskeysched, DES_DECRYPT);
+    DES_ecb_encrypt((DES_cblock *) ibuf, (DES_cblock *) ibuf, &
+		    seskeysched, DES_DECRYPT);
     if (memcmp(seskey, ibuf, sizeof(seskey))) 
 	err = AFPERR_NOTAUTH;
     else if (memcmp(seskey, ibuf + PASSWDLEN, sizeof(seskey)) == 0)
         err = AFPERR_PWDSAME;
