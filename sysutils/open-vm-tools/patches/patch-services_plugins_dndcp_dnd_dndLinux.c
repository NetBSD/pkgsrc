$NetBSD: patch-services_plugins_dndcp_dnd_dndLinux.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- services/plugins/dndcp/dnd/dndLinux.c.orig	2016-02-16 20:06:48.000000000 +0000
+++ services/plugins/dndcp/dnd/dndLinux.c
@@ -39,7 +39,7 @@
 #include "util.h"
 #include "escape.h"
 #include "su.h"
-#if defined(linux) || defined(sun) || defined(__FreeBSD__)
+#if defined(linux) || defined(sun) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "vmblock_user.h"
 #include "mntinfo.h"
 #endif
@@ -276,7 +276,7 @@ DnD_UriIsNonFileSchemes(const char *uri)
 
 
 /* We need to make this suck less. */
-#if defined(linux) || defined(sun) || defined(__FreeBSD__)
+#if defined(linux) || defined(sun) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 /*
  *----------------------------------------------------------------------------
