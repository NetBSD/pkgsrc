$NetBSD: patch-tcl_tcl2cpp_tcl2cpp.c,v 1.1 2013/03/02 18:01:05 joerg Exp $

--- tcl/tcl2cpp/tcl2cpp.c.orig	2013-03-01 14:55:53.000000000 +0000
+++ tcl/tcl2cpp/tcl2cpp.c
@@ -38,6 +38,7 @@ void put(int c)
 		printf("%u,%c", c, ((++n & 0xf) == 0) ? '\n' : ' ');
 }
 
+int
 main(int argc, char **argv)
 {
 	int c;
