$NetBSD: patch-config_gmp__version.c,v 1.1 2025/07/02 03:12:02 markd Exp $

main() returns int

--- config/gmp_version.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/gmp_version.c
@@ -1,4 +1,4 @@
 #include <stdio.h>
 #include <gmp.h>
 void f(void) { mpn_gcdext(NULL,NULL, NULL, NULL, 0, NULL, 0); }
-main(){ printf("%s", gmp_version); }
+int main(){ printf("%s", gmp_version); }
