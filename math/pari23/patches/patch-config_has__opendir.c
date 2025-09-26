$NetBSD: patch-config_has__opendir.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/has_opendir.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_opendir.c
@@ -1,3 +1,3 @@
 #include <sys/types.h>
 #include <dirent.h>
-main() { DIR *d = opendir("."); }
+int main() { DIR *d = opendir("."); }
