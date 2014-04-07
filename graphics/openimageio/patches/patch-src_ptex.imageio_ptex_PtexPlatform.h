$NetBSD: patch-src_ptex.imageio_ptex_PtexPlatform.h,v 1.1 2014/04/07 12:15:55 ryoon Exp $

--- src/ptex.imageio/ptex/PtexPlatform.h.orig	2014-04-03 06:08:57.000000000 +0000
+++ src/ptex.imageio/ptex/PtexPlatform.h
@@ -60,7 +60,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 // linux/unix/posix
 #include <stdlib.h>
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <string.h>
