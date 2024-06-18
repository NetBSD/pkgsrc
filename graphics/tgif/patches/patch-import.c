$NetBSD: patch-import.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- import.c.orig	2011-06-14 03:30:36.000000000 +0000
+++ import.c
@@ -1385,7 +1385,7 @@ int ConvertGifToPpm6(pszGifPath, pszPpm6
 static
 int FinishImport(remote_file, remote_tmp_fname, local_fname, which, pn_image_w,
       pn_image_h)
-   int remote_file, *pn_image_w, *pn_image_h;
+   int remote_file, which, *pn_image_w, *pn_image_h;
    char *remote_tmp_fname, *local_fname;
 {
    char xpm_fname[MAXPATHLENGTH+1], *rest=NULL, *psz_format=NULL;
