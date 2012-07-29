$NetBSD: patch-modules_misc_gnutls.c,v 1.1 2012/07/29 17:37:58 marino Exp $

Mainly due to lack of bits for new fcntl flags, O_DIRECTORY isn't currently
supported by DragonFly's open.  This patch checks which flags are supported
before passing them to vlc_open.

--- modules/misc/gnutls.c.orig	2012-01-27 18:24:46.000000000 +0000
+++ modules/misc/gnutls.c
@@ -469,7 +469,14 @@ static void gnutls_Addx509Directory (vlc
                                      const char *path, bool priv)
 {
     msg_Dbg (obj, "browsing x509 credentials in %s...", path);
-    int fd = vlc_open (path, O_RDONLY|O_DIRECTORY);
+    int flags = 0;
+#ifdef O_RDONLY
+    flags |= O_RDONLY;
+#endif
+#ifdef O_DIRECTORY
+    flags |= O_DIRECTORY;
+#endif
+    int fd = vlc_open (path, flags);
     if (fd == -1)
     {
         msg_Warn (obj, "cannot access x509 in %s: %m", path);
