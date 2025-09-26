$NetBSD: patch-config_has__getrusage.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/has_getrusage.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_getrusage.c
@@ -4,4 +4,4 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <unistd.h>
-main(){ struct rusage a; printf("%d",getrusage(0,&a));}
+int main(){ struct rusage a; printf("%d",getrusage(0,&a));}
