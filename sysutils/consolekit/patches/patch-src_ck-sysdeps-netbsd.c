$NetBSD: patch-src_ck-sysdeps-netbsd.c,v 1.3 2018/06/04 01:01:23 youri Exp $

Fix NetBSD build.

--- src/ck-sysdeps-netbsd.c.orig	2017-06-02 01:31:44.000000000 +0000
+++ src/ck-sysdeps-netbsd.c
@@ -36,7 +36,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
 #include <sys/ioctl.h>
 
 #ifdef HAVE_SYS_MOUNT_H
@@ -121,7 +120,7 @@ ck_process_stat_get_tty (CkProcessStat *
 {
         g_return_val_if_fail (stat != NULL, NULL);
 
-        if (stat->tty == NODEV){
+        if (stat->tty == ENODEV){
                 return NULL;
         }
 
@@ -164,7 +163,7 @@ stat2proc (pid_t        pid,
         }
 
         num = KI_MAXCOMLEN;
-        if (num >= sizeof(P->cmd)) {
+        if ((unsigned)num >= sizeof(P->cmd)) {
                 num = sizeof(P->cmd) - 1;
         }
 
@@ -494,7 +493,11 @@ ck_make_tmpfs (guint uid, guint gid, con
 
         opts = g_strdup_printf ("mode=0700,uid=%d", uid);
 
+#ifdef __NetBSD__
+	result = mount("tmpfs", dest, 0, opts, strlen(opts));
+#else
         result = mount("tmpfs", dest, 0, opts);
+#endif
 
         g_free (opts);
 
