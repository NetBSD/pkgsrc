$NetBSD: patch-ptex.imageio_ptex_PtexPlatform.h,v 1.1 2012/12/03 12:54:15 ryoon Exp $

* Treat NetBSD like FreeBSD

--- ptex.imageio/ptex/PtexPlatform.h.orig	2012-11-16 23:02:42.000000000 +0000
+++ ptex.imageio/ptex/PtexPlatform.h
@@ -60,7 +60,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 // linux/unix/posix
 #include <stdlib.h>
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <string.h>
