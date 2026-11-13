$NetBSD: patch-lib_krb5_os_locate__kdc.c,v 1.4 2026/11/13 11:19:28 jperkin Exp $

Avoid sun conflict.

--- lib/krb5/os/locate_kdc.c.orig	2026-11-13 10:53:07.568714860 +0000
+++ lib/krb5/os/locate_kdc.c
@@ -296,16 +296,16 @@ locate_srv_conf_1(krb5_context context,
 
 #ifndef _WIN32
         if (hostspec[0] == '/') {
-            struct sockaddr_un sun = { 0 };
+            struct sockaddr_un sockun = { 0 };
 
-            sun.sun_family = AF_UNIX;
-            if (strlcpy(sun.sun_path, hostspec, sizeof(sun.sun_path)) >=
-                sizeof(sun.sun_path)) {
+            sockun.sun_family = AF_UNIX;
+            if (strlcpy(sockun.sun_path, hostspec, sizeof(sockun.sun_path)) >=
+                sizeof(sockun.sun_path)) {
                 code = ENAMETOOLONG;
                 goto cleanup;
             }
-            code = add_addr_to_list(serverlist, UNIXSOCK, AF_UNIX, sizeof(sun),
-                                    (struct sockaddr *)&sun);
+            code = add_addr_to_list(serverlist, UNIXSOCK, AF_UNIX, sizeof(sockun),
+                                    (struct sockaddr *)&sockun);
             if (code)
                 goto cleanup;
             continue;
