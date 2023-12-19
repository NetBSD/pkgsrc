$NetBSD: patch-src_user.c,v 1.2 2023/12/19 00:49:52 gutteridge Exp $

Add NetBSD backend inspired from OpenBSD ports.

--- src/user.c.orig	2016-01-11 15:42:31.000000000 +0000
+++ src/user.c
@@ -138,17 +138,14 @@ account_type_from_pwent (struct passwd *
                 return ACCOUNT_TYPE_STANDARD;
         }
         wheel = grp->gr_gid;
-
         ngroups = get_user_groups (pwent->pw_name, pwent->pw_gid, &groups);
 
         for (i = 0; i < ngroups; i++) {
                 if (groups[i] == wheel) {
-                        g_free (groups);
                         return ACCOUNT_TYPE_ADMINISTRATOR;
                 }
         }
 
-        g_free (groups);
 
         return ACCOUNT_TYPE_STANDARD;
 }
@@ -159,6 +156,8 @@ user_update_from_pwent (User          *u
 {
 #ifdef HAVE_SHADOW_H
         struct spwd *spent;
+#else
+        struct passwd *pw;
 #endif
         gchar *real_name;
         gboolean changed;
@@ -264,7 +263,23 @@ user_update_from_pwent (User          *u
                 passwd = spent->sp_pwdp;
 #endif
 
+#ifdef __NetBSD__
+        pw = getpwnam (pwent->pw_name);
+        if (pw)
+                passwd = pw->pw_passwd;
+        if (g_strcmp0(passwd, "skey") == 0)
+                passwd = NULL;
+#endif
+
+
+/* On NetBSD, a locked account has its password
+ * prepended by "*LOCKED*"
+ */
+#ifdef __NetBSD__
+        if (passwd && passwd[0] == '*') {
+#else
         if (passwd && passwd[0] == '!') {
+#endif
                 locked = TRUE;
         }
         else {
@@ -1546,17 +1561,30 @@ user_change_locked_authorized_cb (Daemon
 {
         gboolean locked = GPOINTER_TO_INT (data);
         GError *error;
+#ifdef __NetBSD__
+        const gchar *argv[6];
+#else
         const gchar *argv[5];
+#endif
 
         if (user->locked != locked) {
                 sys_log (context,
                          "%s account of user '%s' (%d)",
                          locked ? "locking" : "unlocking", user->user_name, user->uid);
+#ifdef __NetBSD__
+                argv[0] = "/usr/sbin/usermod";
+                argv[1] = "-C";
+                argv[2] = locked ? "yes" : "no";
+                argv[3] = "--";
+                argv[4] = user->user_name;
+                argv[5] = NULL;
+#else
                 argv[0] = "/usr/sbin/usermod";
                 argv[1] = locked ? "-L" : "-U";
                 argv[2] = "--";
                 argv[3] = user->user_name;
                 argv[4] = NULL;
+#endif
 
                 error = NULL;
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1650,11 +1678,16 @@ user_change_account_type_authorized_cb (
                 for (i = 0; i < ngroups; i++) {
                         if (groups[i] == wheel)
                                 continue;
+
                         g_string_append_printf (str, "%d,", groups[i]);
                 }
                 switch (account_type) {
                 case ACCOUNT_TYPE_ADMINISTRATOR:
+#ifdef __NetBSD__
+                        g_string_append_printf (str, "%s", "wheel");
+#else
                         g_string_append_printf (str, "%d", wheel);
+#endif
                         break;
                 case ACCOUNT_TYPE_STANDARD:
                 default:
@@ -1735,6 +1768,8 @@ user_change_password_mode_authorized_cb 
                 if (mode == PASSWORD_MODE_SET_AT_LOGIN ||
                     mode == PASSWORD_MODE_NONE) {
 
+/* Find a way to remove the password properly XXX */
+#ifndef __NetBSD__
                         argv[0] = "/usr/bin/passwd";
                         argv[1] = "-d";
                         argv[2] = "--";
@@ -1768,6 +1803,7 @@ user_change_password_mode_authorized_cb 
                         user->password_hint = NULL;
 
                         g_object_notify (G_OBJECT (user), "password-hint");
+#endif
 
                         /* removing the password has the side-effect of
                          * unlocking the account
@@ -1778,11 +1814,20 @@ user_change_password_mode_authorized_cb 
                         }
                 }
                 else if (user->locked) {
+#ifdef __NetBSD__
+                        argv[0] = "/usr/sbin/usermod";
+                        argv[1] = "-C";
+                        argv[2] = "no";
+                        argv[3] = "--";
+                        argv[4] = user->user_name;
+                        argv[5] = NULL;
+#else
                         argv[0] = "/usr/sbin/usermod";
                         argv[1] = "-U";
                         argv[2] = "--";
                         argv[3] = user->user_name;
                         argv[4] = NULL;
+#endif
 
                         error = NULL;
                         if (!spawn_with_login_uid (context, argv, &error)) {
