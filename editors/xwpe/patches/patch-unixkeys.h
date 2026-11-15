$NetBSD: patch-unixkeys.h,v 1.1 2026/11/15 13:14:45 vins Exp $

Replace hard-coded paths.

--- unixkeys.h.orig	2026-11-15 09:45:23.102504421 +0000
+++ unixkeys.h
@@ -6,11 +6,11 @@
 /* GNU General Public License, see the file COPYING.      */
 
 #ifndef LIBRARY_DIR
-#define LIBRARY_DIR "/usr/local/lib/xwpe"
+#define LIBRARY_DIR "/usr/@PREFIX@/lib/xwpe"
 #endif
 
 #ifndef INFO_DIR
-#define INFO_DIR "/usr/share/info:/usr/local/info:/usr/info"
+#define INFO_DIR "/usr/share/info:/usr/local/info:/usr/@PREFIX@/@PKGINFODIR@"
 #endif
 
 #define XWPE_HOME   ".xwpe"
