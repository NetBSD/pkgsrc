$NetBSD: patch-src_polkit_polkitunixprocess.c,v 1.7 2025/01/15 08:41:38 adam Exp $

Fix SunOS includes.
Fix pid_t type.

--- src/polkit/polkitunixprocess.c.orig	2024-08-08 13:12:35.000000000 +0000
+++ src/polkit/polkitunixprocess.c
@@ -20,6 +20,11 @@
  */
 
 #include <sys/types.h>
+#ifdef HAVE_SOLARIS
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <procfs.h>
+#endif
 #ifdef HAVE_FREEBSD
 #include <sys/param.h>
 #include <sys/sysctl.h>
@@ -175,7 +180,7 @@ enum
 
 static void subject_iface_init (PolkitSubjectIface *subject_iface);
 
-static guint64 get_start_time_for_pid (gint    pid,
+static guint64 get_start_time_for_pid (pid_t pid,
                                        GError **error);
 
 #if defined(HAVE_FREEBSD) || defined(HAVE_NETBSD) || defined(HAVE_OPENBSD)
