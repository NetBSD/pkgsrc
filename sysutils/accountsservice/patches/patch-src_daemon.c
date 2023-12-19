$NetBSD: patch-src_daemon.c,v 1.2 2023/12/19 00:49:52 gutteridge Exp $

Add NetBSD backend inspired from OpenBSD ports.

--- src/daemon.c.orig	2015-02-25 13:51:44.000000000 +0000
+++ src/daemon.c
@@ -29,6 +29,7 @@
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <pwd.h>
+#include <grp.h>
 #include <unistd.h>
 #include <errno.h>
 #include <sys/types.h>
@@ -46,9 +47,13 @@
 #include "util.h"
 
 #define PATH_PASSWD "/etc/passwd"
+#if defined(HAVE_SHADOW_H)
 #define PATH_SHADOW "/etc/shadow"
+#elif defined(__NetBSD__)
+#define PATH_SHADOW "/etc/master.passwd"
+#endif
 #define PATH_GROUP "/etc/group"
 #define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
 
 enum {
         PROP_0,
@@ -1083,6 +1088,34 @@ daemon_delete_user_authorized_cb (Daemon
                 return;
         }
 
+/*
+ * Under NetBSD there is no /etc/login.defs (for USERGROUPS_ENAB), so
+ * we need to explicitly remove the user's group if it contains no other
+ * members and matches the username.
+ */
+#ifdef __NetBSD__
+        struct group *grp;
+        GError *grperror;
+        const gchar *grpargv[3];
+
+        grp = getgrnam (pwent->pw_name);
+
+        if ((grp != NULL) && (*grp->gr_name == *pwent->pw_name) && (*grp->gr_mem == NULL)) {
+                sys_log (context, "delete group '%d'", pwent->pw_gid);
+
+                grpargv[0] = "/usr/sbin/groupdel";
+                grpargv[1] = pwent->pw_name;
+                grpargv[2] = NULL;
+
+                grperror = NULL;
+                if (!spawn_with_login_uid (context, grpargv, &grperror)) {
+                    throw_error (context, ERROR_FAILED, "running '%s' failed: %s", grpargv[0], grperror->message);
+                    g_error_free (grperror);
+                    return;
+                }
+        }
+#endif
+
         sys_log (context, "delete user '%s' (%d)", pwent->pw_name, ud->uid);
 
         if (daemon->priv->autologin != NULL) {
@@ -1108,11 +1141,18 @@ daemon_delete_user_authorized_cb (Daemon
 
         argv[0] = "/usr/sbin/userdel";
         if (ud->remove_files) {
+#ifdef __NetBSD__
+                argv[1] = "-r";
+                argv[2] = "--";
+                argv[3] = pwent->pw_name;
+                argv[4] = NULL;
+#else
                 argv[1] = "-f";
                 argv[2] = "-r";
                 argv[3] = "--";
                 argv[4] = pwent->pw_name;
                 argv[5] = NULL;
+#endif
         }
         else {
                 argv[1] = "-f";
