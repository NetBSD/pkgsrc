$NetBSD: patch-bfd_sysdep.h,v 1.3 2024/05/25 08:56:12 js Exp $

Fix building on NetBSD.

--- bfd/sysdep.h.orig	2024-05-25 08:44:17.970606532 +0000
+++ bfd/sysdep.h
@@ -29,9 +29,6 @@
 #include "config.h"
 #include <stdio.h>
 
-#if defined(MORPHOS_TARGET) && !defined(__off64_t_defined)
-typedef int64_t         off64_t;
-#endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
@@ -65,6 +62,10 @@ typedef int64_t         off64_t;
 #endif
 #endif
 
+#if defined(MORPHOS_TARGET) && !defined(__off64_t_defined)
+typedef int64_t         off64_t;
+#endif
+
 #ifndef O_RDONLY
 #define O_RDONLY 0
 #endif
