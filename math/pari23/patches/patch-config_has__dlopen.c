$NetBSD: patch-config_has__dlopen.c,v 1.1 2025/09/26 20:24:34 prlw1 Exp $

main() returns int

--- config/has_dlopen.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_dlopen.c
@@ -1,3 +1,3 @@
 #include <stdio.h>
 #include <dlfcn.h>
-main() {dlopen("a",RTLD_LAZY);}
+int main() {dlopen("a",RTLD_LAZY);}
