$NetBSD: patch-util.c,v 1.1 2020/01/09 12:12:17 wiz Exp $

%m is only allowed in syslog(3) like functions [-Wformat=]
https://github.com/googleprojectzero/halfempty/pull/11

--- util.c.orig	2019-03-16 17:55:00.000000000 +0000
+++ util.c
@@ -129,7 +129,7 @@ gboolean generate_dot_tree(GNode *root, 
     FILE *out = fopen(filename, "w");
 
     if (!out) {
-        g_warning("failed to open file `%s` to save dot file, %m", filename);
+        g_warning("failed to open file `%s` to save dot file, %s", filename, strerror(errno));
         return false;
     }
 
