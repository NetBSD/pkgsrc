$NetBSD: patch-bin_tools_arpaname.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* C syntax.

--- bin/tools/arpaname.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ bin/tools/arpaname.c
@@ -14,7 +14,7 @@
 #include <isc/net.h>
 #include <isc/print.h>
 
-#define UNUSED(x) (void)(x)
+#define UNUSED(x) (void)&(x)
 
 int
 main(int argc, char *argv[]) {
