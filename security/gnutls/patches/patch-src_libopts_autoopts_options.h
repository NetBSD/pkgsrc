$NetBSD: patch-src_libopts_autoopts_options.h,v 1.2 2015/06/01 21:50:22 spz Exp $

Workaround for older OSX.

--- src/libopts/autoopts/options.h.orig	2015-03-23 07:19:23.000000000 +0000
+++ src/libopts/autoopts/options.h
@@ -62,7 +62,7 @@
 #    include <sysexits.h>
 #  endif /* HAVE_SYSEXITS_H */
 
-#  if defined(HAVE_STDBOOL_H)
+#  if defined(HAVE_STDBOOL_H) || defined(__APPLE__)
 #    include <stdbool.h>
 #  else
      typedef enum { false = 0, true = 1 } _Bool;
