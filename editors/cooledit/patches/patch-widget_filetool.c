$NetBSD: patch-widget_filetool.c,v 1.1 2026/10/20 20:57:33 ktnb Exp $

NetBSD uses sys/extattr.h

--- widget/filetool.c.orig	2026-10-20 19:25:13.573979850 +0000
+++ widget/filetool.c
@@ -8,7 +8,7 @@
 #include <time.h>
 #include <math.h>
 #include <errno.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/extattr.h>
 #elif defined(__sun) || defined(__sun__)
 #include <fcntl.h>
@@ -250,7 +250,7 @@ static void set_junction_xattr (const char *path)
 
 static void set_junction_xattr (const char *path)
 {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     const char val[] = "1";
     if (extattr_set_link (path, EXTATTR_NAMESPACE_USER, "windows.junction", val, 1) < 0)
         fprintf (stderr, "Warning: could not set xattr on %s: %s\n", path, strerror (errno));
