$NetBSD: patch-services-bsd.c,v 1.1 2017/09/16 09:30:26 wiz Exp $

Drop usage of MNT_HIDDEN on NetBSD.
--- src/platform/services-bsd.c~	2017-09-09 03:11:03.000000000 -0400
+++ src/platform/services-bsd.c	2017-09-14 15:10:22.000000000 -0400
@@ -246,9 +246,6 @@
 #if defined(__FreeBSD__)
 	{ MNT_GJOURNAL,           "gjournal"            },
 #endif
-#if defined(__NetBSD__)
-	{ MNT_HIDDEN,           "hidden"            },
-#endif
 #if defined(__APPLE__)
 	{ MNT_JOURNALED,          "journaled"          },
 #endif
