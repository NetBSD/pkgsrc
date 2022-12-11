$NetBSD: patch-bin_named_os.c,v 1.1 2022/12/11 01:57:55 sekiya Exp $

* Take from NetBSD base.

--- bin/named/os.c.orig	2021-09-07 09:37:05.000000000 +0000
+++ bin/named/os.c
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
