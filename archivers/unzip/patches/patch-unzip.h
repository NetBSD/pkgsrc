$NetBSD: patch-unzip.h,v 1.1 2025/08/24 16:58:07 kikadf Exp $

Fix CVE-2019-13232
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part1.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part2.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part3.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-manpage.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part4.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part5.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part6.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-switch.patch

--- unzip.h.orig	2025-08-23 16:31:36.969582988 +0200
+++ unzip.h
@@ -559,6 +559,7 @@ typedef struct _UzpOpts {
 #ifdef UNIX
     int cflxflag;       /* -^: allow control chars in extracted filenames */
 #endif
+  int zipbomb;
 #endif /* !FUNZIP */
 } UzpOpts;
 
@@ -645,6 +646,7 @@ typedef struct _Uzp_cdir_Rec {
 #define PK_NOZIP           9   /* zipfile not found */
 #define PK_PARAM          10   /* bad or illegal parameters specified */
 #define PK_FIND           11   /* no files found */
+#define PK_BOMB           12   /* likely zip bomb */
 #define PK_DISK           50   /* disk full */
 #define PK_EOF            51   /* unexpected EOF */
 
