$NetBSD: patch-Settings.c,v 1.1 2025/03/11 20:09:53 fox Exp $

https://github.com/htop-dev/htop/pull/1634

Fix build when using native curses.

--- Settings.c.orig	2025-03-10 20:22:40.410153171 +0000
+++ Settings.c
@@ -14,6 +14,7 @@ in the source distribution for its full 
 #include <fcntl.h>
 #include <limits.h>
 #include <pwd.h>
+#include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
