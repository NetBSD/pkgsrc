$NetBSD: patch-config_has__sigaction.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/has_sigaction.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_sigaction.c
@@ -1,5 +1,5 @@
 #include <signal.h>
-main()
+int main()
 {
   struct sigaction sa, oldsa;
 
