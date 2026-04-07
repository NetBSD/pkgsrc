$NetBSD: patch-lib_krb5_os_locate__kdc.c,v 1.1 2026/04/07 14:12:48 tnn Exp $

https://github.com/krb5/krb5/commit/ad4dcf1856dadc4b352b5c8ff08e51c7290fb41f

--- lib/krb5/os/locate_kdc.c.orig	2025-08-20 19:44:32.000000000 +0000
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
