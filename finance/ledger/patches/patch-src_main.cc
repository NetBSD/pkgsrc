$NetBSD: patch-src_main.cc,v 1.2 2023/04/27 13:16:35 yhardy Exp $

Canonicalize pkgsrc readline.h filename.  This is seen both by
consumers of devel/readline and by consumers of devel/editline, via
buildlink3 magic.  The only reason editline/readline.h may exist is to
allow both devel/readline and devel/editline to coexist.

--- src/main.cc.orig	2023-03-03 10:49:39.000000000 +0000
+++ src/main.cc
@@ -40,7 +40,7 @@
 #endif
 
 #ifdef HAVE_EDIT
-#include <editline/readline.h>
+#include <readline/readline.h>
 #endif
 
 using namespace ledger;
