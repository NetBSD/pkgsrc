$NetBSD: patch-src_core_Platform.h,v 1.2 2019/09/18 22:30:49 nia Exp $

No alloca on netbsd, too

--- src/core/Platform.h.orig	2019-03-28 05:12:57.000000000 +0000
+++ src/core/Platform.h
@@ -85,7 +85,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 // assume linux/unix/posix
 
 #include <stdlib.h>
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <string.h>
