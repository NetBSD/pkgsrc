$NetBSD: patch-icb_c__hush.c,v 1.1 2013/01/11 13:24:32 joerg Exp $

--- icb/c_hush.c.orig	2013-01-11 12:17:01.000000000 +0000
+++ icb/c_hush.c
@@ -71,7 +71,7 @@ char *nick;
 	return(0);
 }
 
-hushlist()
+void hushlist(void)
 {
 	STRLIST *p;
 	char *s, *t;
