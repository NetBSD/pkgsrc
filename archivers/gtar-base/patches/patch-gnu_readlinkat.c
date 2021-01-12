$NetBSD: patch-gnu_readlinkat.c,v 1.3 2021/01/12 12:10:27 ryoon Exp $

* workaround for NetBSD-5.x, readlink is defined as a macro.

--- gnu/readlinkat.c.orig	2021-01-07 14:29:45.000000000 +0000
+++ gnu/readlinkat.c
@@ -103,6 +103,7 @@ rpl_readlinkat (int fd, char const *file
 # define AT_FUNC_POST_FILE_PARAM_DECLS , char *buf, size_t bufsize
 # define AT_FUNC_POST_FILE_ARGS        , buf, bufsize
 # define AT_FUNC_RESULT ssize_t
+# undef readlink
 # include "at-func.c"
 # undef AT_FUNC_NAME
 # undef AT_FUNC_F1
