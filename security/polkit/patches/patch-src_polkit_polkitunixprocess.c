$NetBSD: patch-src_polkit_polkitunixprocess.c,v 1.5 2018/05/15 09:09:22 jperkin Exp $

Fix SunOS includes.
Fix pid_t type.

--- src/polkit/polkitunixprocess.c.orig	2018-03-23 15:09:30.000000000 +0000
+++ src/polkit/polkitunixprocess.c
@@ -24,6 +24,11 @@
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
@@ -87,7 +92,7 @@ enum
 
 static void subject_iface_init (PolkitSubjectIface *subject_iface);
 
-static guint64 get_start_time_for_pid (gint    pid,
+static guint64 get_start_time_for_pid (pid_t pid,
                                        GError **error);
 
 static gint _polkit_unix_process_get_owner (PolkitUnixProcess  *process,
