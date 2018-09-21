$NetBSD: patch-src_post.c,v 1.1 2018/09/21 14:27:37 wiz Exp $

Switched <c-lock> element generation to libcanlock API V3.

--- src/post.c.orig	2016-10-23 22:34:16.000000000 +0000
+++ src/post.c
@@ -50,7 +50,7 @@
 #endif
 
 #if SLRN_HAS_CANLOCK
-# include <canlock.h>
+# include <libcanlock-3/canlock.h>
 #endif
 
 #include "slrn.h"
@@ -821,7 +821,7 @@ static int prepare_header (VFILE *vp, un
 
    if ((NULL == (tmp = slrn_gen_date_header ()))
        || (NULL == slrn_append_to_header (a, tmp, 1))
-       || (NULL == (tmp = slrn_strdup_printf("User-Agent: slrn/%s (%s)", Slrn_Version_String, system_os_name)))
+       || (NULL == (tmp = slrn_strdup_printf("User-Agent: slrn/%s (Patched for libcanlock3) (%s)", Slrn_Version_String, system_os_name)))
        || (NULL == slrn_append_to_header (a, tmp, 1))
        || (NULL == slrn_append_to_header (a, NULL,0)))   /* separator */
      {
@@ -1297,6 +1297,7 @@ static char *gen_cancel_lock (char *msgi
    char *buf, *canlock;
    unsigned int filelen;
    char canfile[SLRN_MAX_PATH_LEN];
+   cl_hash_version algo;
 
    cansecret = slrn_open_home_file (file, "r", canfile, SLRN_MAX_PATH_LEN, 0);
    if (cansecret == NULL)
@@ -1323,11 +1324,28 @@ static char *gen_cancel_lock (char *msgi
    (void) fread (buf, filelen, 1, cansecret);
    (void) fclose(cansecret);
 
-# if 0
-   canlock = md5_lock(buf, filelen, msgid, strlen(msgid));
-# else /* by default we use SHA-1 */
-   canlock = sha_lock ((unsigned char *) buf, filelen, (unsigned char *)msgid, strlen(msgid));
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
+   canlock = cl_get_lock (algo, (unsigned char *) buf, filelen, (unsigned char *)msgid, strlen(msgid));
+   /* Try to overwrite secret in memory */
+   cl_clear_secret((void *) buf, filelen, filelen+1);
+
    slrn_free (buf);
    return canlock;
 }
