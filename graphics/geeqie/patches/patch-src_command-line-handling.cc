$NetBSD: patch-src_command-line-handling.cc,v 1.1 2025/10/07 11:11:13 wiz Exp $

https://github.com/BestImageViewer/geeqie/pull/1946

../src/command-line-handling.cc: In function 'void {anonymous}::gq_get_rectangle(GtkApplication*, GApplicationCommandLine*, GVariantDict*, GList*)':
../src/command-line-handling.cc:818:65: error: 'abs' is not a member of 'std'; did you mean 'abs'?
  818 |                                                            std::abs(x1 - x2),
      |                                                                 ^~~

--- src/command-line-handling.cc.orig	2025-10-07 11:06:43.252035335 +0000
+++ src/command-line-handling.cc
@@ -20,6 +20,7 @@
 
 #include "command-line-handling.h"
 
+#include <cmath>
 #include <vector>
 
 #include "cache-maint.h"
