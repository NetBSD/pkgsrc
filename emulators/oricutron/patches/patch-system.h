$NetBSD: patch-system.h,v 1.1 2026/02/14 14:17:10 nia Exp $

Find static files in the right system directory.

--- system.h.orig	2026-02-14 12:37:39.888037767 +0000
+++ system.h
@@ -63,8 +63,8 @@
 
 #define PATHSEP '/'
 #define PATHSEPSTR "/"
-#define ROMPREFIX "roms"PATHSEPSTR
-#define IMAGEPREFIX "images"PATHSEPSTR
+#define ROMPREFIX "@PREFIX@/share/oricutron/roms"PATHSEPSTR
+#define IMAGEPREFIX "@PREFIX@/share/oricutron/images"PATHSEPSTR
 #endif
 
 const char* get_fileprefix();
