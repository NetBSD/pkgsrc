$NetBSD: patch-config_has__TIOCGWINSZ.c,v 1.1 2025/09/26 20:24:34 prlw1 Exp $

main() returns int

--- config/has_TIOCGWINSZ.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_TIOCGWINSZ.c
@@ -2,4 +2,4 @@
 #include <sys/types.h>
 #include <sys/termios.h>
 #include <sys/ioctl.h>
-main() { int x = TIOCGWINSZ; }
+int main() { int x = TIOCGWINSZ; }
