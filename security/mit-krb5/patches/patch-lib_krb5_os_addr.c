$NetBSD: patch-lib_krb5_os_addr.c,v 1.1 2026/04/10 10:38:05 jperkin Exp $

Avoid sun conflict.

--- lib/krb5/os/addr.c.orig	2026-04-10 10:08:05.637992098 +0000
+++ lib/krb5/os/addr.c
@@ -62,10 +62,10 @@ k5_sockaddr_to_address(const struct sock
         }
 #ifndef _WIN32
     } else if (sa->sa_family == AF_UNIX && local_use) {
-        const struct sockaddr_un *sun = sa2sun(sa);
+        const struct sockaddr_un *sockun = sa2sun(sa);
         out->addrtype = ADDRTYPE_UNIXSOCK;
-        out->length = strlen(sun->sun_path);
-        out->contents = (uint8_t *)sun->sun_path;
+        out->length = strlen(sockun->sun_path);
+        out->contents = (uint8_t *)sockun->sun_path;
 #endif
     } else {
         return KRB5_PROG_ATYPE_NOSUPP;
