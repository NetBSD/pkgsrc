$NetBSD: patch-scripts_Python_modules_readline_readline.cpp,v 1.1 2016/03/28 13:13:55 kamil Exp $

--- scripts/Python/modules/readline/readline.cpp.orig	2015-10-19 01:16:17.000000000 +0000
+++ scripts/Python/modules/readline/readline.cpp
@@ -6,7 +6,7 @@
 #include <stdio.h>
 
 #ifndef LLDB_DISABLE_LIBEDIT
-#include <editline/readline.h>
+#include <readline/readline.h>
 #endif
 
 // Simple implementation of the Python readline module using libedit.
