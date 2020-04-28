$NetBSD: patch-lib_libcli.c,v 1.1 2020/04/28 15:22:43 manu Exp $

Fix build for missing struct timeval definition

--- lib/libcli.c.orig	2020-04-27 17:08:53.316497742 +0200
+++ lib/libcli.c	2020-04-27 17:18:12.464903450 +0200
@@ -10,8 +10,9 @@
 #include <string.h>
 #include <ctype.h>
 #include <unistd.h>
 #include <regex.h>
+#include <time.h>
 #include "libcli.h"
 // vim:sw=8 ts=8
 
 enum cli_states
