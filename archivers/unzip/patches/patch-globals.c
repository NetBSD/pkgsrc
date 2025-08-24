$NetBSD: patch-globals.c,v 1.1 2025/08/24 16:58:07 kikadf Exp $

Fix CVE-2019-13232
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part1.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part2.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part3.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-manpage.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part4.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part5.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part6.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-switch.patch


--- globals.c.orig	2025-08-23 16:31:09.322300882 +0200
+++ globals.c
@@ -181,6 +181,7 @@ Uz_Globs *globalsCtor()
 # if (!defined(NO_TIMESTAMPS))
     uO.D_flag=1;    /* default to '-D', no restoration of dir timestamps */
 # endif
+    G.cover = NULL;     /* not allocated yet */
 #endif
 
     uO.lflag=(-1);
