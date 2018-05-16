$NetBSD: patch-src_ck-sysdeps-netbsd.c,v 1.2 2018/05/16 11:30:36 youri Exp $

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
@@ -494,7 +493,11 @@ ck_make_tmpfs (guint uid, guint gid, con
 
         opts = g_strdup_printf ("mode=0700,uid=%d", uid);
 
+#ifdef __NetBSD__
+	result = mount("tmpfs", dest, 0, opts, strlen(opts));
+#else
         result = mount("tmpfs", dest, 0, opts);
+#endif
 
         g_free (opts);
 
