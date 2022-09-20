$NetBSD: patch-mixctl.h,v 1.1 2022/09/20 06:30:48 nia Exp $

Simplify OSS header inclusion situation. Should help DragonFly, Solaris...

--- mixctl.h.orig	2001-03-02 10:32:05.000000000 +0000
+++ mixctl.h
@@ -15,14 +15,10 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
-#ifdef __NetBSD__
-#include <soundcard.h>
-#endif
-#ifdef __FreeBSD__
-#include <machine/soundcard.h>
-#endif
 #ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
 #endif
 
 class MixCtl
