$NetBSD: patch-src_polkitbackend_polkitbackendinteractiveauthority.c,v 1.1 2016/05/20 18:39:33 youri Exp $

* for *BSD netgroup functions

--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2015-06-19 20:39:58.000000000 +0000
+++ src/polkitbackend/polkitbackendinteractiveauthority.c
@@ -23,7 +23,12 @@
 #include <errno.h>
 #include <pwd.h>
 #include <grp.h>
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#define BSD_NETGROUP
+#else
 #include <netdb.h>
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
@@ -2224,7 +2229,7 @@ get_users_in_net_group (PolkitIdentity  
   ret = NULL;
   name = polkit_unix_netgroup_get_name (POLKIT_UNIX_NETGROUP (group));
 
-#ifdef HAVE_SETNETGRENT_RETURN
+#if HAVE_SETNETGRENT_RETURN && !defined(__NetBSD__)
   if (setnetgrent (name) == 0)
     {
       g_warning ("Error looking up net group with name %s: %s", name, g_strerror (errno));
