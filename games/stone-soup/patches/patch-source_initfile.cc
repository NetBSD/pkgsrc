$NetBSD: patch-source_initfile.cc,v 1.1 2019/08/08 13:40:30 nia Exp $

We need unistd for unlink(2), depending on UNIX being defined
(the same approach is used in files.cc).

--- source/initfile.cc.orig	2018-09-17 02:40:29.000000000 +0000
+++ source/initfile.cc
@@ -88,6 +88,8 @@ extern char **NXArgv;
 #endif
 #elif defined(TARGET_OS_LINUX) || defined(TARGET_OS_CYGWIN)
 #include <unistd.h>
+#elif defined(UNIX)
+#include <unistd.h>
 #endif
 
 const string game_options::interrupt_prefix = "interrupt_";
