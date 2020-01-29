$NetBSD: patch-src_zipcmp.c,v 1.1 2020/01/29 21:54:31 wiz Exp $

Avoid double free.
https://github.com/nih-at/libzip/commit/bd9fb11fa88f6a95b8afbd53796934adf4e6e6bd

--- src/zipcmp.c.orig	2020-01-24 11:03:14.000000000 +0000
+++ src/zipcmp.c
@@ -248,7 +248,6 @@ compare_zip(char *const zn[]) {
 	}
 	for (j = 0; j < a[i].nentry; j++) {
 	    free(a[i].entry[j].name);
-	    free(a[i].entry[j].extra_fields);
 	}
 	free(a[i].entry);
     }
