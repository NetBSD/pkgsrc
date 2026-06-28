$NetBSD: patch-src_main.cc,v 1.3 2026/06/28 16:29:15 wiz Exp $

Canonicalize pkgsrc readline.h filename.  This is seen both by
consumers of devel/readline and by consumers of devel/editline, via
buildlink3 magic.  The only reason editline/readline.h may exist is to
allow both devel/readline and devel/editline to coexist.

--- src/main.cc.orig	2025-12-07 21:59:44.630131187 +0000
+++ src/main.cc
@@ -40,7 +40,7 @@
 #endif
 
 #if HAVE_EDIT
-#include <editline/readline.h>
+#include <readline/readline.h>
 #elif HAVE_READLINE
 #include <readline/readline.h>
 #include <readline/history.h>
