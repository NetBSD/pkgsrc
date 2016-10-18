$NetBSD: patch-src_ptex_PtexPlatform.h,v 1.1 2016/10/18 02:47:17 kamil Exp $

The alloca(3) function is an extension and place of its definition varies.
The <alloca.h> header is required on SunOS and acceptable on other systems, but
unavailable on NetBSD.

--- src/ptex/PtexPlatform.h.orig	2016-04-04 17:14:05.000000000 +0000
+++ src/ptex/PtexPlatform.h
@@ -62,7 +62,9 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 // linux/unix/posix
 #include <stdlib.h>
+#if !defined(__NetBSD__)
 #include <alloca.h>
+#endif
 #include <string.h>
 #include <pthread.h>
 
