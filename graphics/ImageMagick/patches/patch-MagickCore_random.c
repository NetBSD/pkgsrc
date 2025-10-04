$NetBSD: patch-MagickCore_random.c,v 1.2 2025/10/04 10:30:48 tnn Exp $

Include correct header for getentropy.

--- MagickCore/random.c.orig	2025-08-30 13:35:00.000000000 +0000
+++ MagickCore/random.c
@@ -65,8 +65,11 @@
 #include "MagickCore/utility.h"
 #include "MagickCore/utility-private.h"
 #if defined(MAGICKCORE_HAVE_GETENTROPY)
+#include <unistd.h>
+#if defined(__APPLE__)
 #include <sys/random.h>
 #endif
+#endif
 /*
   Define declarations.
 */
