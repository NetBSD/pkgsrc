$NetBSD: patch-lib-src_emacsclient.c,v 1.1 2020/08/23 20:12:34 wiz Exp $

Workaround for:
On NetBSD, fstat on a socket returns zero instead of the user id.
Reported upstream as http://debbugs.gnu.org/cgi/bugreport.cgi?bug=43002

--- lib-src/emacsclient.c.orig	2020-07-29 21:40:41.000000000 +0000
+++ lib-src/emacsclient.c
@@ -1478,6 +1478,11 @@ set_local_socket (char const *server_nam
       struct stat connect_stat;
       if (fstat (s, &connect_stat) != 0)
 	sock_status = errno;
+#if defined(__NetBSD__)
+      else if (1) {
+        return s;
+      }
+#endif
       else if (connect_stat.st_uid == uid)
 	return s;
       else
