$NetBSD: patch-sntp_libopts_usage.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- sntp/libopts/usage.c.orig	2015-04-26 18:43:15.000000000 +0000
+++ sntp/libopts/usage.c
@@ -762,7 +762,7 @@ prt_vendor_opts(tOptions * opts, char co
         OPTST_NO_USAGE_MASK | OPTST_DOCUMENT;
 
     static char const vfmtfmt[] = "%%-%us %%s\n";
-    char vfmt[sizeof(vfmtfmt)];
+    char vfmt[sizeof(vfmtfmt)+10]; /* strlen(UINT_MAX) */
 
     /*
      *  Only handle client specified options.  The "vendor option" follows
