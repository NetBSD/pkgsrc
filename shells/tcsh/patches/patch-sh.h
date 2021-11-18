$NetBSD: patch-sh.h,v 1.2 2021/11/18 10:20:47 kim Exp $

Add OpenBSD support.

Don't glob the filetest builtin arguments twice:    
    https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=905649

https://github.com/tcsh-org/tcsh/commit/8a83d4c717ad4a56450751986b65ccd6ea9eed8a.patch

--- sh.h.orig	2021-11-11 09:54:05.000000000 +0000
+++ sh.h	2021-11-18 10:03:48.441361892 +0000
@@ -320,7 +320,7 @@
  * redefines malloc(), so we define the following
  * to avoid it.
  */
-# if defined(SYSMALLOC) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(sgi) || defined(_OSD_POSIX)
+# if defined(SYSMALLOC) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(sgi) || defined(_OSD_POSIX) || defined(__OpenBSD__)
 #  define NO_FIX_MALLOC
 #  include <stdlib.h>
 # else /* glibc */
@@ -1299,4 +1299,8 @@
 
 #include "tc.nls.h"
 
+#define TEXP_IGNORE 1	/* in ignore, it means to ignore value, just parse */
+#define TEXP_NOGLOB 2	/* in ignore, it means not to globone */
+
+
 #endif /* _h_sh */
