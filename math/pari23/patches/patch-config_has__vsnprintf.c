$NetBSD: patch-config_has__vsnprintf.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/has_vsnprintf.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_vsnprintf.c
@@ -1,7 +1,7 @@
 #include <stdio.h>
 #include <stdarg.h>
 
-main() {}
+int main() {}
 int f(int i,...) { char s[1]; va_list ap; va_start(ap,i);
   vsnprintf(s,1,"",ap); return 0;
 }
