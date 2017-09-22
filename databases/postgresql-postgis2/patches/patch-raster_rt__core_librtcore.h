$NetBSD: patch-raster_rt__core_librtcore.h,v 1.1 2017/09/22 17:18:42 gdt Exp $

Work around configure code that fails to check HAVE_STRNICMP because
the previous twisty maze of defines do not define UNIX.  Complaint
submitted upstream; this patch would break Windows (which is ok in
pkgsrc).

--- raster/rt_core/librtcore.h.orig	2016-07-04 15:45:56.000000000 +0000
+++ raster/rt_core/librtcore.h
@@ -58,61 +58,10 @@
 #ifndef LIBRTCORE_H_INCLUDED
 #define LIBRTCORE_H_INCLUDED
 
-/* define the systems */
-#if defined(__linux__)  /* (predefined) */
-#if !defined(LINUX)
-#define LINUX
-#endif
-#if !defined(UNIX)
-#define UNIX        /* make sure this is defined */
-#endif
-#endif
-
-
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)    /* seems to work like Linux... */
-#if !defined(LINUX)
-#define LINUX
-#endif
-#if !defined(UNIX)
-#define UNIX        /* make sure this is defined */
-#endif
-#endif
-
-#if defined(__GNU__)    /* GNU/Hurd is also like Linux */
-#if !defined(LINUX)
-#define LINUX
-#endif
-#if !defined(UNIX)
-#define UNIX        /* make sure this is defined */
-#endif
-#endif
-
-#if defined(__MSDOS__)
-#if !defined(MSDOS)
-#define MSDOS       /* make sure this is defined */
-#endif
-#endif
-
-#if defined(__WIN32__) || defined(__NT__) || defined(_WIN32)
-#if !defined(WIN32)
-#define WIN32
-#endif
-#if defined(__BORLANDC__) && defined(MSDOS) /* Borland always defines MSDOS */
-#undef  MSDOS
-#endif
-#endif
-
-#if defined(__APPLE__)
-#if !defined(UNIX)
+/* For pkgsrc, assume POSIX. */
+#ifndef UNIX
 #define UNIX
-#endif
-#endif
-
-#if defined(sun) || defined(__sun)
-#if !defined(UNIX)
-#define UNIX
-#endif
-#endif
+#endif /* UNIX */
 
 /* if we are in Unix define stricmp to be strcasecmp and strnicmp to */
 /* be strncasecmp. I'm not sure if all Unices have these, but Linux */
