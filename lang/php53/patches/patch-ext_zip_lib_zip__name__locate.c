$NetBSD: patch-ext_zip_lib_zip__name__locate.c,v 1.1.2.2 2011/02/23 19:12:54 tron Exp $

Catch up to r307867 from PHP's repogitry for SA43328.

--- ext/zip/lib/zip_name_locate.c.orig	2008-05-21 09:27:41.000000000 +0000
+++ ext/zip/lib/zip_name_locate.c
@@ -60,6 +60,10 @@ _zip_name_locate(struct zip *za, const c
 	return -1;
     }
 
+    if((flags & ZIP_FL_UNCHANGED)  && !za->cdir) {
+	return -1;
+    }
+
     cmp = (flags & ZIP_FL_NOCASE) ? strcmpi : strcmp;
 
     n = (flags & ZIP_FL_UNCHANGED) ? za->cdir->nentry : za->nentry;
