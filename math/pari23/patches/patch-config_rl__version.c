$NetBSD: patch-config_rl__version.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/rl_version.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/rl_version.c
@@ -9,4 +9,4 @@
 extern char *rl_library_version; /* Might be mismatched header, try anyway! */
 #endif
 
-main(){ printf("%s", rl_library_version); }
+int main(){ printf("%s", rl_library_version); }
