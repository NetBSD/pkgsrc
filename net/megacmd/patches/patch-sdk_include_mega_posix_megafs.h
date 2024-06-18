$NetBSD: patch-sdk_include_mega_posix_megafs.h,v 1.1 2024/06/18 18:23:15 bsiegert Exp $

Add support to other BSDs.
Upstream pull req: https://github.com/meganz/sdk/pull/2662

--- sdk/include/mega/posix/megafs.h.orig	2024-05-17 14:19:43.000000000 +0000
+++ sdk/include/mega/posix/megafs.h
@@ -32,7 +32,7 @@
 #define O_DIRECT 0
 #include <sys/param.h>
 #include <sys/mount.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/mount.h>
 #else
 #include <sys/vfs.h>
