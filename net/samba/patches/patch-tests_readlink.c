$NetBSD: patch-tests_readlink.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add stdlib.h.

Add int return type for main().

--- ../tests/readlink.c.orig	2026-07-21 20:53:52.444069676 +0000
+++ ../tests/readlink.c
@@ -7,10 +7,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <stdlib.h>
 
 #define DATA "readlink.test"
 #define FNAME "rdlnk.file"
 
+int
 main()
 {
 	char buf[7];
