$NetBSD: patch-storage_innobase_include_univ.i,v 1.1.2.2 2019/09/08 16:55:18 bsiegert Exp $

* Stop another useless warnings.

--- storage/innobase/include/univ.i.orig	2019-06-10 10:25:32.000000000 +0000
+++ storage/innobase/include/univ.i
@@ -123,7 +123,9 @@ Sun Studio */
 #endif /* #if (defined(WIN32) || ... */
 
 #ifndef __WIN__
+#ifndef __STDC_FORMAT_MACROS
 #define __STDC_FORMAT_MACROS    /* Enable C99 printf format macros */
+#endif
 #include <inttypes.h>
 #endif /* !__WIN__ */
 
