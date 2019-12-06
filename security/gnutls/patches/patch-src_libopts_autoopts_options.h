$NetBSD: patch-src_libopts_autoopts_options.h,v 1.3 2019/12/06 14:00:08 nia Exp $

Workaround for older OSX.

--- src/libopts/autoopts/options.h.orig	2019-12-01 21:25:38.000000000 +0000
+++ src/libopts/autoopts/options.h
@@ -62,7 +62,7 @@
 #    include <sysexits.h>
 #  endif /* HAVE_SYSEXITS_H */
 
-#  if defined(HAVE_STDBOOL_H)
+#  if defined(HAVE_STDBOOL_H) || defined(__APPLE__)
 #    include <stdbool.h>
 #  elif ! defined(bool)
      typedef enum { false = 0, true = 1 } _Bool;
