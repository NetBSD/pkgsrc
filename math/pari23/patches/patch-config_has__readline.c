$NetBSD: patch-config_has__readline.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/has_readline.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_readline.c
@@ -3,4 +3,4 @@
 #else
 #  include <readline/readline.h>
 #endif
-main() { char *s = readline("?"); }
+int main() { char *s = readline("?"); }
