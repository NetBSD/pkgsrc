$NetBSD: patch-config_has__strftime.c,v 1.1 2025/09/26 20:24:35 prlw1 Exp $

main() returns int

--- config/has_strftime.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/has_strftime.c
@@ -1,2 +1,2 @@
 #include <time.h>
-main(){ struct tm *x; strftime("",1,"",x);}
+int main(){ struct tm *x; strftime("",1,"",x);}
