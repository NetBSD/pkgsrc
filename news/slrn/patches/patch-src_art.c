$NetBSD: patch-src_art.c,v 1.1 2018/09/21 14:27:37 wiz Exp $

Switched <c-key> element generation to libcanlock API V3.

--- src/art.c.orig	2016-10-23 22:34:16.000000000 +0000
+++ src/art.c
@@ -74,7 +74,7 @@
 #include "decode.h"
 
 #if SLRN_HAS_CANLOCK
-# include <canlock.h>
+# include <libcanlock-3/canlock.h>
 #endif
 
 #if SLRN_HAS_GROUPLENS
@@ -3660,6 +3660,7 @@ static char* gen_cancel_key (char* msgid
    char *buf, *cankey;
    unsigned int filelen;
    char canfile[SLRN_MAX_PATH_LEN];
+   cl_hash_version algo;
 
    if (0 == *Slrn_User_Info.cancelsecret)
      return NULL;
@@ -3686,14 +3687,30 @@ static char* gen_cancel_key (char* msgid
      }
    (void) fseek (cansecret, 0, SEEK_SET);
    (void) fread (buf, filelen, 1, cansecret);
+   (void) fclose (cansecret);
 
-# if 0
-   cankey = md5_key (buf, filelen, msgid, strlen(msgid));
-# else /* by default we use SHA-1 */
-   cankey = sha_key ((unsigned char *) buf, filelen, (unsigned char *)msgid, strlen(msgid));
-# endif
+   /* Fixme: This check is used twice, should be moved to a central location */
+   if (0 == slrn_case_strcmp (Slrn_User_Info.canlock_algo, "SHA1"))
+   {
+      algo = CL_SHA1;
+   }
+   else if (0 == slrn_case_strcmp (Slrn_User_Info.canlock_algo, "SHA256"))
+   {
+      algo = CL_SHA256;
+   }
+   else if (0 == slrn_case_strcmp (Slrn_User_Info.canlock_algo, "SHA512"))
+   {
+      algo = CL_SHA512;
+   }
+   else
+   {
+      slrn_error (_("Cancel-Lock algorithm not supported: %s"), Slrn_User_Info.canlock_algo);
+      return NULL;
+   }
+   cankey = cl_get_key (algo, (unsigned char *) buf, filelen, (unsigned char *)msgid, strlen(msgid));
+   /* Try to overwrite secret in memory */
+   cl_clear_secret((void *) buf, filelen, filelen+1);
 
-   fclose (cansecret);
    slrn_free (buf);
    return cankey;
 }
