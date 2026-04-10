$NetBSD: patch-lib_krb5_os_locate__kdc.c,v 1.2 2026/04/10 10:38:05 jperkin Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f
Avoid sun conflict.

--- lib/krb5/os/locate_kdc.c.orig	2026-01-29 23:18:10.000000000 +0000
+++ lib/krb5/os/locate_kdc.c
@@ -214,8 +214,8 @@ oom:
 }
 
 static void
-parse_uri_if_https(const char *host_or_uri, k5_transport *transport,
-                   const char **host, const char **uri_path)
+parse_uri_if_https(char *host_or_uri, k5_transport *transport,
+                   char **host, const char **uri_path)
 {
     char *cp;
 
@@ -257,8 +257,7 @@ locate_srv_conf_1(krb5_context context,
                   k5_transport transport, int udpport)
 {
     const char *realm_srv_names[4];
-    char **hostlist = NULL, *realmstr = NULL, *host = NULL;
-    const char *hostspec;
+    char **hostlist = NULL, *realmstr = NULL, *host = NULL, *hostspec;
     krb5_error_code code;
     size_t i;
     int default_port;
@@ -297,16 +296,16 @@ locate_srv_conf_1(krb5_context context,
 
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
@@ -587,8 +586,8 @@ prof_locate_server(krb5_context context,
  * Return a NULL *host_out if there are any problems parsing the URI.
  */
 static void
-parse_uri_fields(const char *uri, k5_transport *transport_out,
-                 const char **host_out, int *primary_out)
+parse_uri_fields(char *uri, k5_transport *transport_out,
+                 char **host_out, int *primary_out)
 
 {
     k5_transport transport;
@@ -656,8 +655,8 @@ locate_uri(krb5_context context, const k
     krb5_error_code ret;
     k5_transport transport, host_trans;
     struct srv_dns_entry *answers, *entry;
-    char *host, *sitename;
-    const char *host_field, *path;
+    char *host, *sitename, *host_field;
+    const char *path;
     int port, def_port, primary;
 
     ret = get_sitename(context, realm, &sitename);
