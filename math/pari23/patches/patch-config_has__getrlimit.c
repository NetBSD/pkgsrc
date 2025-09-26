$NetBSD: patch-config_has__getrlimit.c,v 1.1 2025/09/26 20:24:34 prlw1 Exp $

main() returns int

--- config/has_getrlimit.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_getrlimit.c
@@ -1,7 +1,7 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
-main() {
+int main() {
   struct rlimit rip;
   getrlimit(RLIMIT_STACK, &rip);
   setrlimit(RLIMIT_STACK, &rip);
