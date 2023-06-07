$NetBSD: patch-src_polkitbackend_polkitbackendinteractiveauthority.c,v 1.3 2023/06/07 15:36:40 wiz Exp $

* for *BSD netgroup functions

--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2022-07-11 08:46:06.000000000 +0000
+++ src/polkitbackend/polkitbackendinteractiveauthority.c
@@ -26,8 +26,13 @@
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
@@ -2250,7 +2255,7 @@ get_users_in_net_group (PolkitIdentity  
   ret = NULL;
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
-#ifdef HAVE_SETNETGRENT_RETURN
+#if defined(HAVE_SETNETGRENT_RETURN) && !defined(__NetBSD__)
   if (setnetgrent (name) == 0)
     {
       g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
