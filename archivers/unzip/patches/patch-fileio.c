$NetBSD: patch-fileio.c,v 1.3 2025/08/24 16:58:07 kikadf Exp $

https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2014-8141
https://sources.debian.org/patches/unzip/6.0-28/28-cve-2022-0529-and-cve-2022-0530.patch/

Fix CVE-2018-1000035
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-6.0-cve-2018-1000035-heap-based-overflow.patch

Fix CVE-2019-13232
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part1.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part2.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part3.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-manpage.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part4.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part5.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part6.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-switch.patch


--- fileio.c.orig	2009-04-20 02:03:44.000000000 +0200
+++ fileio.c
@@ -1,5 +1,5 @@
 /*
-  Copyright (c) 1990-2009 Info-ZIP.  All rights reserved.
+  Copyright (c) 1990-2017 Info-ZIP.  All rights reserved.
 
   See the accompanying file LICENSE, version 2009-Jan-02 or later
   (the contents of which are also included in unzip.h) for terms of use.
@@ -171,11 +171,15 @@ static ZCONST char Far ReadError[] = "er
 static ZCONST char Far FilenameTooLongTrunc[] =
   "warning:  filename too long--truncating.\n";
 #ifdef UNICODE_SUPPORT
+   static ZCONST char Far UFilenameCorrupt[] =
+     "error: Unicode filename corrupt.\n";
    static ZCONST char Far UFilenameTooLongTrunc[] =
-     "warning:  Converted unicode filename too long--truncating.\n";
+     "warning:  Converted Unicode filename too long--truncating.\n";
 #endif
 static ZCONST char Far ExtraFieldTooLong[] =
   "warning:  extra field too long (%d).  Ignoring...\n";
+static ZCONST char Far ExtraFieldCorrupt[] =
+  "warning:  extra field (type: 0x%04x) corrupt.  Continuing...\n";
 
 #ifdef WINDLL
    static ZCONST char Far DiskFullQuery[] =
@@ -530,8 +534,10 @@ void undefer_input(__G)
          * This condition was checked when G.incnt_leftover was set > 0 in
          * defer_leftover_input(), and it is NOT allowed to touch G.csize
          * before calling undefer_input() when (G.incnt_leftover > 0)
-         * (single exception: see read_byte()'s  "G.csize <= 0" handling) !!
+         * (single exception: see readbyte()'s  "G.csize <= 0" handling) !!
          */
+        if (G.csize < 0L)
+            G.csize = 0L;
         G.incnt = G.incnt_leftover + (int)G.csize;
         G.inptr = G.inptr_leftover - (int)G.csize;
         G.incnt_leftover = 0;
@@ -1580,6 +1586,8 @@ int UZ_EXP UzpPassword (pG, rcnt, pwbuf,
     int r = IZ_PW_ENTERED;
     char *m;
     char *prompt;
+    char *ep;
+    char *zp;
 
 #ifndef REENTRANT
     /* tell picky compilers to shut up about "unused variable" warnings */
@@ -1588,9 +1596,12 @@ int UZ_EXP UzpPassword (pG, rcnt, pwbuf,
 
     if (*rcnt == 0) {           /* First call for current entry */
         *rcnt = 2;
-        if ((prompt = (char *)malloc(2*FILNAMSIZ + 15)) != (char *)NULL) {
-            sprintf(prompt, LoadFarString(PasswPrompt),
-                    FnFilter1(zfn), FnFilter2(efn));
+        zp = FnFilter1( zfn);
+        ep = FnFilter2( efn);
+        prompt = (char *)malloc(        /* Slightly too long (2* "%s"). */
+         sizeof( PasswPrompt)+ strlen( zp)+ strlen( ep));
+        if (prompt != (char *)NULL) {
+            sprintf(prompt, LoadFarString(PasswPrompt), zp, ep);
             m = prompt;
         } else
             m = (char *)LoadFarString(PasswPrompt2);
@@ -2295,7 +2306,12 @@ int do_string(__G__ length, option)   /*
             if (readbuf(__G__ (char *)G.extra_field, length) == 0)
                 return PK_EOF;
             /* Looks like here is where extra fields are read */
-            getZip64Data(__G__ G.extra_field, length);
+            if (getZip64Data(__G__ G.extra_field, length) != PK_COOL)
+            {
+                Info(slide, 0x401, ((char *)slide,
+                 LoadFarString( ExtraFieldCorrupt), EF_PKSZ64));
+                error = PK_WARN;
+            }
 #ifdef UNICODE_SUPPORT
             G.unipath_filename = NULL;
             if (G.UzO.U_flag < 2) {
@@ -2340,16 +2356,30 @@ int do_string(__G__ length, option)   /*
                   /* convert UTF-8 to local character set */
                   fn = utf8_to_local_string(G.unipath_filename,
                                             G.unicode_escape_all);
-                  /* make sure filename is short enough */
-                  if (strlen(fn) >= FILNAMSIZ) {
-                    fn[FILNAMSIZ - 1] = '\0';
+
+                  /* 2022-07-22 SMS, et al.  CVE-2022-0530
+                   * Detect conversion failure, emit message.
+                   * Continue with unconverted name.
+                   */
+                  if (fn == NULL)
+                  {
                     Info(slide, 0x401, ((char *)slide,
-                      LoadFarString(UFilenameTooLongTrunc)));
-                    error = PK_WARN;
+                     LoadFarString(UFilenameCorrupt)));
+                    error = PK_ERR;
+                  }
+                  else
+                  {
+                    /* make sure filename is short enough */
+                    if (strlen(fn) >= FILNAMSIZ) {
+                      fn[FILNAMSIZ - 1] = '\0';
+                      Info(slide, 0x401, ((char *)slide,
+                        LoadFarString(UFilenameTooLongTrunc)));
+                      error = PK_WARN;
+                    }
+                    /* replace filename with converted UTF-8 */
+                    strcpy(G.filename, fn);
+                    free(fn);
                   }
-                  /* replace filename with converted UTF-8 */
-                  strcpy(G.filename, fn);
-                  free(fn);
                 }
 # endif /* UNICODE_WCHAR */
                 if (G.unipath_filename != G.filename_full)
