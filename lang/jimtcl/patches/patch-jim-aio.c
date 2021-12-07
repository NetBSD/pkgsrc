$NetBSD: patch-jim-aio.c,v 1.1 2021/12/07 17:51:21 jperkin Exp $

Avoid sun define on SunOS.

--- jim-aio.c.orig	2021-11-27 23:06:54.000000000 +0000
+++ jim-aio.c
@@ -132,7 +132,7 @@ union sockaddr_any {
     struct sockaddr_in6 sin6;
 #endif
 #if UNIX_SOCKETS
-    struct sockaddr_un sun;
+    struct sockaddr_un sockun;
 #endif
 };
 
@@ -530,9 +530,9 @@ static int JimParseIpAddress(Jim_Interp
 #if UNIX_SOCKETS
 static int JimParseDomainAddress(Jim_Interp *interp, const char *path, union sockaddr_any *sa, socklen_t *salen)
 {
-    sa->sun.sun_family = PF_UNIX;
-    snprintf(sa->sun.sun_path, sizeof(sa->sun.sun_path), "%s", path);
-    *salen = strlen(sa->sun.sun_path) + 1 + sizeof(sa->sun.sun_family);
+    sa->sockun.sun_family = PF_UNIX;
+    snprintf(sa->sockun.sun_path, sizeof(sa->sockun.sun_path), "%s", path);
+    *salen = strlen(sa->sockun.sun_path) + 1 + sizeof(sa->sockun.sun_family);
 
     return JIM_OK;
 }
@@ -567,8 +567,8 @@ static Jim_Obj *JimFormatSocketAddress(J
     switch (sa->sa.sa_family) {
 #if UNIX_SOCKETS
         case PF_UNIX:
-            addr = sa->sun.sun_path;
-            addrlen = salen - 1 - sizeof(sa->sun.sun_family);
+            addr = sa->sockun.sun_path;
+            addrlen = salen - 1 - sizeof(sa->sockun.sun_family);
             if (addrlen < 0) {
                 addrlen = 0;
             }
