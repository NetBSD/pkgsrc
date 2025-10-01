$NetBSD: patch-MagickCore_random.c,v 1.1 2025/10/01 10:52:58 nia Exp $

Include correct header for getentropy.

--- MagickCore/random.c.orig	2025-10-01 10:27:19.831792297 +0000
+++ MagickCore/random.c
@@ -65,7 +65,7 @@
 #include "MagickCore/utility.h"
 #include "MagickCore/utility-private.h"
 #if defined(MAGICKCORE_HAVE_GETENTROPY)
-#include <sys/random.h>
+#include <unistd.h>
 #endif
 /*
   Define declarations.
