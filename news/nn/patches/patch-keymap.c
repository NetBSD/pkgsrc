$NetBSD: patch-keymap.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- keymap.c.orig	2026-05-16 21:27:20.712632233 +0000
+++ keymap.c
@@ -6,7 +6,7 @@
  */
 
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "init.h"
@@ -638,7 +638,7 @@ cmd_completion(char *path, int index)
     if (path) {
 	head = path;
 	tail = path + index;
-	while (*head && isspace(*head))
+	while (*head && ISSPACE(*head))
 	    head++;
 	help_cmd = cmd = command_name_map;
 	len = tail - head;
@@ -731,7 +731,7 @@ parse_key(char *str)
 	    return CONTROL_(str[1]);
     }
 
-    if (isdigit(str[0])) {
+    if (ISDIGIT(str[0])) {
 	if (str[0] == '0') {
 	    if (str[1] == 'x')
 		sscanf(str + 2, "%d", &x);
@@ -743,7 +743,7 @@ parse_key(char *str)
 
 	return x;
     }
-    if (str[0] == '#' && isdigit(str[1]))
+    if (str[0] == '#' && ISDIGIT(str[1]))
 	return K_function(str[1] - '0');
 
     if (str[0] == '#')
@@ -990,7 +990,7 @@ keymap_completion(char *buf, int ix)
     if (buf) {
 	head = buf;
 	tail = buf + ix;
-	while (*head && isspace(*head))
+	while (*head && ISSPACE(*head))
 	    head++;
 	help_map = map = keymaps;
 	len = tail - head;
