$NetBSD: patch-qjsc.c,v 1.1 2019/11/14 21:20:04 rillig Exp $

Portability patch for NetBSD.

--- qjsc.c.orig	2019-11-14 20:58:23.645680708 +0000
+++ qjsc.c
@@ -450,7 +450,9 @@ static int output_executable(const char 
              lib_dir, bn_suffix, lto_suffix);
     *arg++ = libjsname;
     *arg++ = "-lm";
+#ifdef CONFIG_LDL
     *arg++ = "-ldl";
+#endif
     *arg = NULL;
     
     if (verbose) {
