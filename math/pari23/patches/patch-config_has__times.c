$NetBSD: patch-config_has__times.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/has_times.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_times.c
@@ -1,7 +1,7 @@
 #include <stdio.h>
 #include <sys/times.h>
 #include <unistd.h>
-main(){
+int main(){
   struct tms t;
   printf("%d%d", times(&t),
 #ifdef _SC_CLK_TCK
