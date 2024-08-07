$NetBSD: patch-fileio.c,v 1.1.78.1 2024/08/07 18:47:45 bsiegert Exp $

https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2014-8141
https://sources.debian.org/patches/unzip/6.0-28/28-cve-2022-0529-and-cve-2022-0530.patch/

--- fileio.c.orig	2009-04-20 00:03:44.000000000 +0000
+++ fileio.c
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
@@ -2295,7 +2299,12 @@ int do_string(__G__ length, option)   /*
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
@@ -2340,16 +2349,30 @@ int do_string(__G__ length, option)   /*
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
