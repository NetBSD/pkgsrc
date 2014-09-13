$NetBSD: patch-dbus_dbus-sysdeps-util-unix.c,v 1.3 2014/09/13 09:47:11 richard Exp $

add solaris specific console_user test

--- dbus/dbus-sysdeps-util-unix.c.orig	2014-01-25 12:39:25.000000000 +0000
+++ dbus/dbus-sysdeps-util-unix.c
@@ -54,6 +54,10 @@
 #include <syslog.h>
 #endif
 
+#if defined(__sun) && defined(__SVR4)
+#include <pwd.h>
+#endif
+
 #ifdef HAVE_SYS_SYSLIMITS_H
 #include <sys/syslimits.h>
 #endif
@@ -556,8 +560,31 @@ _dbus_user_at_console (const char *usern
 
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
@@ -582,6 +609,7 @@ _dbus_user_at_console (const char *usern
 
  out:
   _dbus_string_free (&f);
+#endif
 
   return result;
 }
