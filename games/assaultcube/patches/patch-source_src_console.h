$NetBSD: patch-source_src_console.h,v 1.1 2020/03/18 17:55:46 joerg Exp $

--- source/src/console.h.orig	2020-03-18 14:22:32.205453475 +0000
+++ source/src/console.h
@@ -1,3 +1,4 @@
+#include <string>
 struct cline { char *line; int millis; };
 
 template<class LINE> struct consolebuffer
