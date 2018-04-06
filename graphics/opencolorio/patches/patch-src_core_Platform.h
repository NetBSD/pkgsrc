$NetBSD: patch-src_core_Platform.h,v 1.1 2018/04/06 03:42:19 maya Exp $

No alloca on netbsd, too

--- src/core/Platform.h.orig	2013-10-08 22:59:34.000000000 +0000
+++ src/core/Platform.h
@@ -85,7 +85,7 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 // linux/unix/posix
 #include <stdlib.h>
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <string.h>
