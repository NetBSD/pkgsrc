$NetBSD: patch-plugins_command_xp_AbiCommand.cpp,v 1.1 2025/12/17 16:38:18 nia Exp $

Include <strings.h> for rindex.

--- plugins/command/xp/AbiCommand.cpp.orig	2025-12-17 13:46:39.994801053 +0000
+++ plugins/command/xp/AbiCommand.cpp
@@ -31,6 +31,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 #include <stdlib.h>
 #include <readline/readline.h>
 #include <readline/history.h>
