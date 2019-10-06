$NetBSD: patch-deadwood-3.2.14_src_DwMain.c,v 1.1 2019/10/06 12:52:20 nia Exp $

Support PKG_SYSCONFDIR.

--- deadwood-3.2.14/src/DwMain.c.orig	2019-01-20 16:22:47.000000000 +0000
+++ deadwood-3.2.14/src/DwMain.c
@@ -66,7 +66,7 @@ void dw_parse_args(int argc, char **argv
                 process_mararc(argv[2]);
         } else {
 #ifndef MINGW
-                process_mararc("/etc/dwood3rc");
+                process_mararc("@PKG_SYSCONFDIR@/maradns/dwood3rc");
 #else /* MINGW */
                 process_mararc("dwood3rc.txt");
 #endif /* MINGW */
