$NetBSD: patch-gnu_readlinkat.c,v 1.1 2015/01/10 16:15:30 gdt Exp $

* workaround for NetBSD-5.x, readlink is defined as a macro.

--- lib/readlinkat.c.orig	2013-06-29 05:54:25.000000000 +0000
+++ lib/readlinkat.c
@@ -41,6 +41,7 @@
 #define AT_FUNC_POST_FILE_PARAM_DECLS , char *buf, size_t len
 #define AT_FUNC_POST_FILE_ARGS        , buf, len
 #define AT_FUNC_RESULT ssize_t
+#undef readlink
 #include "at-func.c"
 #undef AT_FUNC_NAME
 #undef AT_FUNC_F1
