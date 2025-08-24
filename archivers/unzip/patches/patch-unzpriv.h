$NetBSD: patch-unzpriv.h,v 1.1 2025/08/24 16:58:07 kikadf Exp $

Fix CVE-2019-13232
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part1.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part2.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part3.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-manpage.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part4.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part5.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part6.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-switch.patch

--- unzpriv.h.orig	2025-08-23 16:31:58.373631717 +0200
+++ unzpriv.h
@@ -2031,6 +2031,7 @@ typedef struct min_info {
 #ifdef UNICODE_SUPPORT
     unsigned GPFIsUTF8: 1;   /* crec gen_purpose_flag UTF-8 bit 11 is set */
 #endif
+    unsigned zip64: 1;       /* true if entry has Zip64 extra block */
 #ifndef SFX
     char Far *cfilname;      /* central header version of filename */
 #endif
@@ -2185,6 +2186,16 @@ typedef struct VMStimbuf {
        int have_ecr64;                  /* valid Zip64 ecdir-record exists */
        int is_zip64_archive;            /* Zip64 ecdir-record is mandatory */
        ush zipfile_comment_length;
+       zusz_t ec_start, ec_end;         /* offsets of start and end of the
+                                           end of central directory record,
+                                           including if present the Zip64
+                                           end of central directory locator,
+                                           which immediately precedes the
+                                           end of central directory record */
+       zusz_t ec64_start, ec64_end;     /* if have_ecr64 is true, then these
+                                           are the offsets of the start and
+                                           end of the Zip64 end of central
+                                           directory record */
    } ecdir_rec;
 
 
