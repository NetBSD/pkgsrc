$NetBSD: patch-app_load_save.c,v 1.1 2015/06/09 08:55:23 wiz Exp $

Allow NetBSD and OpenBSD to compile by exposing the fchmod() prototype.
This has been reported upstream as:
https://bugzilla.gnome.org/show_bug.cgi?id=750536

--- app/load_save.c.orig    2014-08-24 11:46:01.000000000 -0400
+++ app/load_save.c
@@ -19,7 +19,14 @@

 /* so we get fdopen declared even when compiling with -ansi */
 #define _POSIX_C_SOURCE 200809L
-#define _BSD_SOURCE 1 /* to get the prototype for fchmod() */
+/* to get the prototype for fchmod() */
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE 1
+#elif defined(__OpenBSD__)
+#define __BSD_VISIBLE 1
+#else
+#define _BSD_SOURCE 1
+#endif

 #include <sys/stat.h>
 #ifdef HAVE_UNISTD_H
