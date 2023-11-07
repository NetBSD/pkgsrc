$NetBSD: patch-src_ptex_PtexPlatform.h,v 1.2 2023/11/07 17:56:56 nros Exp $

The alloca(3) function is an extension and place of its definition varies.
The <alloca.h> header is required on SunOS and acceptable on other systems, but
unavailable on NetBSD so use CMake to test for it.
<alloca.h> is not needed when using Ptex. 

--- src/ptex/PtexPlatform.h.orig	2022-08-05 02:02:51.000000000 +0000
+++ src/ptex/PtexPlatform.h
@@ -70,7 +70,9 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 
 // linux/unix/posix
 #include <stdlib.h>
+#if defined(PTEX_HAVE_ALLOCA_H)
 #include <alloca.h>
+#endif
 #include <string.h>
 #include <pthread.h>
 
