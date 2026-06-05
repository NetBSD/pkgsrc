$NetBSD: patch-src_polkitbackend_polkitbackendinteractiveauthority.c,v 1.6 2026/06/05 22:16:44 wiz Exp $

* for *BSD netgroup functions
https://github.com/polkit-org/polkit/pull/624

--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2025-12-17 16:14:53.000000000 +0000
+++ src/polkitbackend/polkitbackendinteractiveauthority.c
@@ -25,8 +25,12 @@
 #ifdef HAVE_NETGROUP_H
 #include <netgroup.h>
 #else
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#else
 #include <netdb.h>
 #endif
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
@@ -2383,7 +2387,7 @@ get_users_in_net_group (PolkitIdentity                
 
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
-# ifdef HAVE_SETNETGRENT_RETURN
+#if defined(HAVE_SETNETGRENT_RETURN) && !defined(__NetBSD__)
   if (setnetgrent (name) == 0)
     {
       g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
