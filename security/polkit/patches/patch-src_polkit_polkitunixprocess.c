$NetBSD: patch-src_polkit_polkitunixprocess.c,v 1.8 2025/12/21 15:44:05 wiz Exp $

Fix SunOS includes.
Fix pid_t type.
https://github.com/polkit-org/polkit/pull/624

--- src/polkit/polkitunixprocess.c.orig	2025-12-17 16:14:53.000000000 +0000
+++ src/polkit/polkitunixprocess.c
@@ -27,6 +27,11 @@
 #include <sys/vfs.h>
 #endif
 #include <sys/types.h>
+#ifdef HAVE_SOLARIS
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <procfs.h>
+#endif
 #ifdef HAVE_FREEBSD
 #include <sys/param.h>
 #include <sys/sysctl.h>
@@ -189,7 +194,7 @@ enum
 
 static void subject_iface_init (PolkitSubjectIface *subject_iface);
 
-static guint64 get_start_time_for_pid (gint    pid,
+static guint64 get_start_time_for_pid (pid_t pid,
                                        GError **error);
 
 static gint
