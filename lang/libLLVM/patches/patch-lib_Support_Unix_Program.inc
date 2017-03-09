$NetBSD: patch-lib_Support_Unix_Program.inc,v 1.1 2017/03/09 12:45:56 jperkin Exp $

Remove bogus redefine.

--- lib/Support/Unix/Program.inc.orig	2016-04-05 20:45:04.000000000 +0000
+++ lib/Support/Unix/Program.inc
@@ -40,9 +40,6 @@
 #include <unistd.h>
 #endif
 #ifdef HAVE_POSIX_SPAWN
-#ifdef __sun__
-#define  _RESTRICT_KYWD
-#endif
 #include <spawn.h>
 
 #if defined(__APPLE__)
