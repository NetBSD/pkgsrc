$NetBSD: patch-Xsra_SFinternal.h,v 1.1 2025/12/13 12:38:10 wiz Exp $

Add missing header for struct stat.

--- Xsra/SFinternal.h.orig	2025-12-13 12:35:21.607585438 +0000
+++ Xsra/SFinternal.h
@@ -30,6 +30,7 @@
 #include <X11/Xos.h>
 #include <X11/Xaw/Text.h>
 #include <X11/Xaw/AsciiText.h>
+#include <sys/stat.h>
 
 #define SEL_FILE_CANCEL		-1
 #define SEL_FILE_OK		0
