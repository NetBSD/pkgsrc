$NetBSD: patch-bin_named_unix_os.c,v 1.1 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- bin/named/unix/os.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ bin/named/unix/os.c
@@ -125,11 +125,10 @@ linux_setcaps(cap_t caps) {
 		}                                                             \
 	} while (0)
 #define FREE_CAP                   \
-	{                          \
+	do {                       \
 		cap_free(caps);    \
 		cap_free(curcaps); \
-	}                          \
-	while (0)
+	} while (0)
 
 static void
 linux_initialprivs(void) {
