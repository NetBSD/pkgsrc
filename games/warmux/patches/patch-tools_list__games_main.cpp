$NetBSD: patch-tools_list__games_main.cpp,v 1.1 2013/04/29 21:31:10 joerg Exp $

--- tools/list_games/main.cpp.orig	2013-04-29 19:45:36.000000000 +0000
+++ tools/list_games/main.cpp
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <unistd.h>
 #include <WARMUX_types.h>
 #include <WARMUX_network.h>
 #include <WARMUX_index_server.h>
