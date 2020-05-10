$NetBSD: patch-bfd_sysdep.h,v 1.1 2020/05/10 02:14:18 js Exp $

--- bfd/sysdep.h.orig	2020-05-10 01:34:09.000000000 +0000
+++ bfd/sysdep.h
@@ -33,9 +33,6 @@
 #endif
 
 #include <stdio.h>
-#if defined(MORPHOS_TARGET) && !defined(__off64_t_defined)
-typedef int64_t         off64_t;
-#endif
 #include <sys/types.h>
 
 #include <errno.h>
@@ -96,6 +93,10 @@ extern char *strrchr ();
 #endif
 #endif
 
+#if defined(MORPHOS_TARGET) && !defined(__off64_t_defined)
+typedef int64_t         off64_t;
+#endif
+
 #ifndef O_RDONLY
 #define O_RDONLY 0
 #endif
