$NetBSD: patch-extra_mariabackup_xtrabackup.cc,v 1.1 2024/08/21 21:08:34 nia Exp $

Fix mariadbbackup core dump.
https://jira.mariadb.org/browse/MDEV-34340

--- extra/mariabackup/xtrabackup.cc.orig	2024-08-03 07:29:56.000000000 +0000
+++ extra/mariabackup/xtrabackup.cc
@@ -69,6 +69,11 @@ Street, Fifth Floor, Boston, MA 02110-13
 # include <sys/sysctl.h>
 #endif
 
+#ifdef __NetBSD__
+# include <sys/param.h>
+# include <sys/sysctl.h>
+#endif
+
 #include "aria_backup_client.h"
 
 #include <btr0sea.h>
@@ -7690,6 +7695,11 @@ static int get_exepath(char *buf, size_t
   if (sysctl(mib, 4, buf, &size, NULL, 0) == 0) {
     return 0;
   }
+#elif defined(__NetBSD__)
+  int mib[4] = {CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME };
+  if (sysctl(mib, 4, buf, &size, NULL, 0) == 0) {
+    return 0;
+  }
 #endif
 
   return my_realpath(buf, argv0, 0);
