$NetBSD: patch-src_polkitbackend_polkitbackendinteractiveauthority.c,v 1.4 2025/01/15 08:41:38 adam Exp $

* for *BSD netgroup functions

--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2024-08-08 13:12:35.000000000 +0000
+++ src/polkitbackend/polkitbackendinteractiveauthority.c
@@ -25,8 +25,13 @@
 #ifdef HAVE_NETGROUP_H
 #include <netgroup.h>
 #else
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#define BSD_NETGROUP
+#else
 #include <netdb.h>
 #endif
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
@@ -2255,7 +2260,7 @@ get_users_in_net_group (PolkitIdentity
 #ifdef HAVE_SETNETGRENT
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
-# ifdef HAVE_SETNETGRENT_RETURN
+#if defined(HAVE_SETNETGRENT_RETURN) && !defined(__NetBSD__)
   if (setnetgrent (name) == 0)
     {
       g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
