$NetBSD: patch-process.c,v 1.2 2024/08/06 14:40:13 nia Exp $

https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2014-8141
https://sources.debian.org/patches/unzip/6.0-28/28-cve-2022-0529-and-cve-2022-0530.patch/

--- process.c.orig	2009-03-06 01:25:10.000000000 +0000
+++ process.c
@@ -1,5 +1,5 @@
 /*
-  Copyright (c) 1990-2009 Info-ZIP.  All rights reserved.
+  Copyright (c) 1990-2014 Info-ZIP.  All rights reserved.
 
   See the accompanying file LICENSE, version 2009-Jan-02 or later
   (the contents of which are also included in unzip.h) for terms of use.
@@ -222,6 +222,8 @@ static ZCONST char Far ZipfileCommTrunc1
      "\nwarning:  Unicode Path version > 1\n";
    static ZCONST char Far UnicodeMismatchError[] =
      "\nwarning:  Unicode Path checksum invalid\n";
+   static ZCONST char Far UFilenameTooLongTrunc[] =
+     "warning:  filename too long (P1) -- truncating.\n";
 #endif
 
 
@@ -1888,48 +1890,83 @@ int getZip64Data(__G__ ef_buf, ef_len)
     and a 4-byte version of disk start number.
     Sets both local header and central header fields.  Not terribly clever,
     but it means that this procedure is only called in one place.
+
+    2014-12-05 SMS.  (oCERT.org report.)  CVE-2014-8141.
+    Added checks to ensure that enough data are available before calling
+    makeint64() or makelong().  Replaced various sizeof() values with
+    simple ("4" or "8") constants.  (The Zip64 structures do not depend
+    on our variable sizes.)  Error handling is crude, but we should now
+    stay within the buffer.
   ---------------------------------------------------------------------------*/
 
+#define Z64FLGS 0xffff
+#define Z64FLGL 0xffffffff
+
     if (ef_len == 0 || ef_buf == NULL)
         return PK_COOL;
 
     Trace((stderr,"\ngetZip64Data: scanning extra field of length %u\n",
       ef_len));
 
-    while (ef_len >= EB_HEADSIZE) {
+    while (ef_len >= EB_HEADSIZE)
+    {
         eb_id = makeword(EB_ID + ef_buf);
         eb_len = makeword(EB_LEN + ef_buf);
 
-        if (eb_len > (ef_len - EB_HEADSIZE)) {
-            /* discovered some extra field inconsistency! */
+        if (eb_len > (ef_len - EB_HEADSIZE))
+        {
+            /* Extra block length exceeds remaining extra field length. */
             Trace((stderr,
               "getZip64Data: block length %u > rest ef_size %u\n", eb_len,
               ef_len - EB_HEADSIZE));
             break;
         }
-        if (eb_id == EF_PKSZ64) {
 
-          int offset = EB_HEADSIZE;
+        if (eb_id == EF_PKSZ64)
+        {
+          unsigned offset = EB_HEADSIZE;
+
+          if ((G.crec.ucsize == Z64FLGL) || (G.lrec.ucsize == Z64FLGL))
+          {
+            if (offset+ 8 > ef_len)
+              return PK_ERR;
 
-          if (G.crec.ucsize == 0xffffffff || G.lrec.ucsize == 0xffffffff){
-            G.lrec.ucsize = G.crec.ucsize = makeint64(offset + ef_buf);
-            offset += sizeof(G.crec.ucsize);
+            G.crec.ucsize = G.lrec.ucsize = makeint64(offset + ef_buf);
+            offset += 8;
           }
-          if (G.crec.csize == 0xffffffff || G.lrec.csize == 0xffffffff){
-            G.csize = G.lrec.csize = G.crec.csize = makeint64(offset + ef_buf);
-            offset += sizeof(G.crec.csize);
+
+          if ((G.crec.csize == Z64FLGL) || (G.lrec.csize == Z64FLGL))
+          {
+            if (offset+ 8 > ef_len)
+              return PK_ERR;
+
+            G.csize = G.crec.csize = G.lrec.csize = makeint64(offset + ef_buf);
+            offset += 8;
           }
-          if (G.crec.relative_offset_local_header == 0xffffffff){
+
+          if (G.crec.relative_offset_local_header == Z64FLGL)
+          {
+            if (offset+ 8 > ef_len)
+              return PK_ERR;
+
             G.crec.relative_offset_local_header = makeint64(offset + ef_buf);
-            offset += sizeof(G.crec.relative_offset_local_header);
+            offset += 8;
           }
-          if (G.crec.disk_number_start == 0xffff){
+
+          if (G.crec.disk_number_start == Z64FLGS)
+          {
+            if (offset+ 4 > ef_len)
+              return PK_ERR;
+
             G.crec.disk_number_start = (zuvl_t)makelong(offset + ef_buf);
-            offset += sizeof(G.crec.disk_number_start);
+            offset += 4;
           }
+#if 0
+          break;                /* Expect only one EF_PKSZ64 block. */
+#endif /* 0 */
         }
 
-        /* Skip this extra field block */
+        /* Skip this extra field block. */
         ef_buf += (eb_len + EB_HEADSIZE);
         ef_len -= (eb_len + EB_HEADSIZE);
     }
@@ -1984,7 +2021,7 @@ int getUnicodeData(__G__ ef_buf, ef_len)
         }
         if (eb_id == EF_UNIPATH) {
 
-          int offset = EB_HEADSIZE;
+          unsigned offset = EB_HEADSIZE;
           ush ULen = eb_len - 5;
           ulg chksum = CRCVAL_INITIAL;
 
@@ -2440,16 +2477,17 @@ char *wide_to_local_string(wide_string, 
   int state_dependent;
   int wsize = 0;
   int max_bytes = MB_CUR_MAX;
-  char buf[9];
+  char buf[ MB_CUR_MAX+ 1];             /* ("+1" not really needed?) */
   char *buffer = NULL;
   char *local_string = NULL;
+  size_t buffer_size;                   /* CVE-2022-0529 */
 
   for (wsize = 0; wide_string[wsize]; wsize++) ;
 
   if (max_bytes < MAX_ESCAPE_BYTES)
     max_bytes = MAX_ESCAPE_BYTES;
-
-  if ((buffer = (char *)malloc(wsize * max_bytes + 1)) == NULL) {
+  buffer_size = wsize * max_bytes + 1;          /* Reused below. */
+  if ((buffer = (char *)malloc( buffer_size)) == NULL) {
     return NULL;
   }
 
@@ -2487,8 +2525,28 @@ char *wide_to_local_string(wide_string, 
     } else {
       /* no MB for this wide */
         /* use escape for wide character */
-        char *escape_string = wide_to_escape_string(wide_string[i]);
-        strcat(buffer, escape_string);
+        size_t buffer_len;
+        size_t escape_string_len;
+        char *escape_string;
+        int err_msg = 0;
+
+        escape_string = wide_to_escape_string(wide_string[i]);
+        buffer_len = strlen( buffer);
+        escape_string_len = strlen( escape_string);
+
+        /* Append escape string, as space allows. */
+        /* 2022-07-18 SMS, et al.  CVE-2022-0529 */
+        if (escape_string_len > buffer_size- buffer_len- 1)
+        {
+            escape_string_len = buffer_size- buffer_len- 1;
+            if (err_msg == 0)
+            {
+                err_msg = 1;
+                Info(slide, 0x401, ((char *)slide,
+                 LoadFarString( UFilenameTooLongTrunc)));
+            }
+        }
+        strncat( buffer, escape_string, escape_string_len);
         free(escape_string);
     }
   }
@@ -2540,9 +2598,18 @@ char *utf8_to_local_string(utf8_string, 
   ZCONST char *utf8_string;
   int escape_all;
 {
-  zwchar *wide = utf8_to_wide_string(utf8_string);
-  char *loc = wide_to_local_string(wide, escape_all);
-  free(wide);
+  zwchar *wide;
+  char *loc = NULL;
+
+  wide = utf8_to_wide_string( utf8_string);
+
+  /* 2022-07-25 SMS, et al.  CVE-2022-0530 */
+  if (wide != NULL)
+  {
+    loc = wide_to_local_string( wide, escape_all);
+    free( wide);
+  }
+
   return loc;
 }
 
