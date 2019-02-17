$NetBSD: patch-src_main.cc,v 1.1 2019/02/17 11:55:03 wiz Exp $

Canonicalize pkgsrc readline.h filename.  This is seen both by
consumers of devel/readline and by consumers of devel/editline, via
buildlink3 magic.  The only reason editline/readline.h may exist is to
allow both devel/readline and devel/editline to coexist.

--- src/main.cc.orig	2019-02-05 13:30:45.000000000 +0000
+++ src/main.cc
@@ -36,7 +36,7 @@
 #include "session.h"
 
 #ifdef HAVE_EDIT
-#include <editline/readline.h>
+#include <readline/readline.h>
 #endif
 
 using namespace ledger;
