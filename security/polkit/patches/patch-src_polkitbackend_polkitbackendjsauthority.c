$NetBSD: patch-src_polkitbackend_polkitbackendjsauthority.c,v 1.2 2016/06/18 12:16:23 youri Exp $

* for *BSD netgroup functions
* for no SIGPOLL
* Fix a memory leak
* Add getgrouplist for SunOS

--- src/polkitbackend/polkitbackendjsauthority.c.orig	2015-06-19 20:39:58.000000000 +0000
+++ src/polkitbackend/polkitbackendjsauthority.c
@@ -24,7 +24,12 @@
 #include <errno.h>
 #include <pwd.h>
 #include <grp.h>
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#define BSD_NETENT
+#else
 #include <netdb.h>
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
@@ -812,7 +817,7 @@ subject_to_jsval (PolkitBackendJsAuthori
   if (passwd == NULL)
     {
       user_name = g_strdup_printf ("%d", (gint) uid);
-      g_warning ("Error looking up info for uid %d: %m", (gint) uid);
+      g_warning ("Error looking up info for uid %d: %s", (gint) uid, g_strerror(errno));
     }
   else
     {
@@ -826,7 +831,7 @@ subject_to_jsval (PolkitBackendJsAuthori
                         gids,
                         &num_gids) < 0)
         {
-          g_warning ("Error looking up groups for uid %d: %m", (gint) uid);
+          g_warning ("Error looking up groups for uid %d: %s", (gint) uid, g_strerror(errno));
         }
       else
         {
@@ -1508,8 +1513,13 @@ js_polkit_user_is_in_netgroup (JSContext
   JSBool ret = JS_FALSE;
   JSString *user_str;
   JSString *netgroup_str;
+#ifdef BSD_NETENT
+  const char *user;
+  const char *netgroup;
+#else
   char *user;
   char *netgroup;
+#endif
   JSBool is_in_netgroup = JS_FALSE;
 
   if (!JS_ConvertArguments (cx, argc, JS_ARGV (cx, vp), "SS", &user_str, &netgroup_str))
@@ -1913,3 +1923,52 @@ utils_spawn_finish (GAsyncResult   *res,
  out:
   return ret;
 }
+
+#ifdef __sun__
+#include <string.h>
+int
+getgrouplist(const char *uname, gid_t agroup, gid_t *groups, int *grpcnt)
+{
+    const struct group *grp;
+    int i, maxgroups, ngroups, ret;
+
+    ret = 0;
+    ngroups = 0;
+    maxgroups = *grpcnt;
+    /*
+     * When installing primary group, duplicate it;
+     * the first element of groups is the effective gid
+     * and will be overwritten when a setgid file is executed.
+     */
+    groups ? groups[ngroups++] = agroup : ngroups++;
+    if (maxgroups > 1)
+        groups ? groups[ngroups++] = agroup : ngroups++;
+    /*
+     * Scan the group file to find additional groups.
+     */
+    setgrent();
+    while ((grp = getgrent()) != NULL) {
+        if (groups) {
+            for (i = 0; i < ngroups; i++) {
+                if (grp->gr_gid == groups[i])
+                    goto skip;
+            }
+        }
+        for (i = 0; grp->gr_mem[i]; i++) {
+            if (!strcmp(grp->gr_mem[i], uname)) {
+                if (ngroups >= maxgroups) {
+                    ret = -1;
+                    break;
+                }
+                groups ? groups[ngroups++] = grp->gr_gid : ngroups++;
+                break;
+            }
+        }
+skip:
+        ;
+    }
+    endgrent();
+    *grpcnt = ngroups;
+    return (ret);
+}
+#endif
