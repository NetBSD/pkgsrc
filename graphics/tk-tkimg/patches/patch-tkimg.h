$NetBSD: patch-tkimg.h,v 1.1 2019/11/10 20:11:30 maya Exp $

Revert version update to make the tests work.

--- tkimg.h.orig	2005-01-24 19:08:06.000000000 +0000
+++ tkimg.h
@@ -8,7 +8,7 @@
 
 #include "tk.h"
 
-#define TKIMG_VERSION "1.3.99"
+#define TKIMG_VERSION "1.3.9"
 
 #if BUILD_tkimg
 #	define TKIMGAPI DLLEXPORT
