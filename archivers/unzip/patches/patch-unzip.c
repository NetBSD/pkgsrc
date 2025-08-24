$NetBSD: patch-unzip.c,v 1.1 2025/08/24 16:58:07 kikadf Exp $

Fix CVE-2019-13232
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part1.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part2.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part3.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-manpage.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part4.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part5.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part6.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-switch.patch


--- unzip.c.orig	2025-08-23 16:32:58.736449614 +0200
+++ unzip.c
@@ -1329,10 +1329,9 @@ int uz_opts(__G__ pargc, pargv)
     int *pargc;
     char ***pargv;
 {
-    char **argv, *s;
+    char **argv, *s, *zipbomb_envar;
     int argc, c, error=FALSE, negative=0, showhelp=0;
 
-
     argc = *pargc;
     argv = *pargv;
 
@@ -1923,6 +1922,18 @@ opts_done:  /* yes, very ugly...but only
     else
         G.extract_flag = TRUE;
 
+    /* Disable the zipbomb detection, this is the only option set only via the shell variables but it should at least not clash with something in the future. */
+    zipbomb_envar = getenv("UNZIP_DISABLE_ZIPBOMB_DETECTION");
+    uO.zipbomb = TRUE;
+    if (zipbomb_envar != NULL) {
+      /* strcasecmp might be a better approach here but it is POSIX-only */
+      if ((strcmp ("TRUE", zipbomb_envar) == 0)
+       || (strcmp ("True", zipbomb_envar) == 0)
+       || (strcmp ("true",zipbomb_envar) == 0)) {
+        uO.zipbomb = FALSE;
+      }
+    }
+
     *pargc = argc;
     *pargv = argv;
     return PK_OK;
