$NetBSD: patch-services_plugins_dndcp_dnd_dndLinux.c,v 1.2 2018/01/01 06:56:01 ryoon Exp $

--- services/plugins/dndcp/dnd/dndLinux.c.orig	2017-12-15 19:09:51.000000000 +0000
+++ services/plugins/dndcp/dnd/dndLinux.c
@@ -40,7 +40,7 @@
 #include "util.h"
 #include "escape.h"
 #include "su.h"
-#if defined(__linux__) || defined(sun) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(sun) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "vmblock_user.h"
 #include "mntinfo.h"
 #endif
@@ -277,7 +277,7 @@ DnD_UriIsNonFileSchemes(const char *uri)
 
 
 /* We need to make this suck less. */
-#if defined(__linux__) || defined(sun) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(sun) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 /*
  *----------------------------------------------------------------------------
