$NetBSD: patch-src_mof_OW__MOFCompiler.cpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/mof/OW_MOFCompiler.cpp.orig	2013-03-25 15:38:25.000000000 +0000
+++ src/mof/OW_MOFCompiler.cpp
@@ -51,6 +51,7 @@
 
 #include <assert.h>
 #include <cctype>
+#include <climits>
 
 // forward declarations of some lex/yacc functions we need to call.
 void owmof_delete_buffer(YY_BUFFER_STATE b);
