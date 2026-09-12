$NetBSD: patch-autoopts_save.c,v 1.1 2026/09/12 12:14:40 wiz Exp $

Check whether text_mmap() failed before scanning what it returned.

CVE-2025-8746.  Taken verbatim from the patch on Savannah sr #111319,
which upstream has not committed.

--- autoopts/save.c.orig	2017-09-11 00:00:00.000000000 +0000
+++ autoopts/save.c
@@ -492,6 +492,9 @@
     size_t const name_len = strlen(opts->pzProgName);
     tmap_info_t  map_info;
     char *       text = text_mmap(fname, PROT_READ|PROT_WRITE, MAP_PRIVATE, &map_info);
+    if (TEXT_MMAP_FAILED_ADDR(text))
+        return;
+
     char *       scan = text;
 
     for (;;) {
