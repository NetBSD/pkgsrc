$NetBSD: patch-dbus_dbus-sysdeps-util-unix.c,v 1.6 2022/10/03 12:44:00 wiz Exp $

add solaris specific console_user test

--- dbus/dbus-sysdeps-util-unix.c.orig	2022-09-14 12:12:21.000000000 +0000
+++ dbus/dbus-sysdeps-util-unix.c
@@ -56,6 +56,10 @@
 #ifdef HAVE_SYS_PRCTL_H
 #include <sys/prctl.h>
 #endif
+#if defined(__sun) && defined(__SVR4)
+#include <pwd.h>
+#endif
+
 
 #ifdef HAVE_SYSTEMD
 #include <systemd/sd-daemon.h>
@@ -578,8 +582,31 @@ _dbus_user_at_console (const char *usern
 #ifdef DBUS_CONSOLE_AUTH_DIR
   DBusString u, f;
   dbus_bool_t result;
+#if defined(__sun) && defined(__SVR4)
+  struct passwd *passwd_entry;
+#endif
 
   result = FALSE;
+
+#if defined(__sun) && defined(__SVR4)
+  passwd_entry = getpwnam (username);
+  if (passwd_entry != NULL)
+    {
+      struct stat st;
+      uid_t uid;
+
+      uid = passwd_entry->pw_uid;
+
+      if (stat ("/dev/vt/console_user", &st) == 0 && st.st_uid == uid)
+        {
+         /*
+          * Owner is allowed to take over. Before we have real
+          * ownership in HAL, assume it's the console owner.
+          */
+          result = TRUE;
+        }
+    }
+#else
   if (!_dbus_string_init (&f))
     {
       _DBUS_SET_OOM (error);
@@ -604,6 +631,7 @@ _dbus_user_at_console (const char *usern
 
  out:
   _dbus_string_free (&f);
+#endif
 
   return result;
 #else
