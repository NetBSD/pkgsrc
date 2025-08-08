$NetBSD: patch-include_terminal.h,v 1.1 2025/08/08 07:23:59 adam Exp $

BSD support https://github.com/hashcat/hashcat/pull/4392

--- include/terminal.h.orig	2025-08-01 21:03:55.000000000 +0000
+++ include/terminal.h
@@ -16,17 +16,19 @@
 #include <windows.h>
 #else
 #include <termios.h>
-#if defined (__APPLE__)
+#if defined (__APPLE__)   || defined (__OpenBSD__)   || defined (__NetBSD__) || \
+    defined (__FreeBSD__) || defined (__DragonFly__)
 #include <sys/ioctl.h>
 #include <sys/sysctl.h>
-#endif // __APPLE__
+#endif
 #endif // _WIN
 
 #if defined (_POSIX)
 #include <sys/utsname.h>
-#if !defined (__APPLE__)
+#if !defined (__APPLE__)   && !defined (__OpenBSD__)   && !defined (__NetBSD__) && \
+    !defined (__FreeBSD__) && !defined (__DragonFly__)
 #include <sys/sysinfo.h>
-#endif // ! __APPLE__
+#endif
 #endif // _POSIX
 
 void welcome_screen (hashcat_ctx_t *hashcat_ctx, const char *version_tag);
