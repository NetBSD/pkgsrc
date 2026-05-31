$NetBSD: patch-extra_zlib_zlib-1.3.2_gzguts.h,v 1.1 2026/05/31 10:47:48 jnemeth Exp $

--- extra/zlib/zlib-1.3.2/gzguts.h.orig	2026-05-25 01:48:03.077284261 +0000
+++ extra/zlib/zlib-1.3.2/gzguts.h
@@ -35,6 +35,7 @@
 #  include <string.h>
 #  include <stdlib.h>
 #  include <limits.h>
+#  include <unistd.h>
 #endif
 
 #ifndef _POSIX_C_SOURCE
