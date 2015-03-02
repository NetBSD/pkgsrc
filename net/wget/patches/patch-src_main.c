$NetBSD: patch-src_main.c,v 1.1 2015/03/02 20:23:07 tron Exp $

Disable progress bar if "-q" option is used. Patch taken from GIT repository:

http://git.savannah.gnu.org/cgit/wget.git/commit/?id=9dde436dd689bd51eef71d64152dde9c8c0b5f65

--- src/main.c.orig	2015-02-10 21:31:49.000000000 +0000
+++ src/main.c	2015-03-02 20:18:15.000000000 +0000
@@ -1272,6 +1272,9 @@
   if (opt.verbose == -1)
     opt.verbose = !opt.quiet;
 
+  if (opt.quiet && opt.show_progress == -1)
+    opt.show_progress = false;
+
   /* Sanity checks.  */
   if (opt.verbose && opt.quiet)
     {
