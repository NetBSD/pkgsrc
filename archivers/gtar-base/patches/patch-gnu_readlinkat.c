$NetBSD: patch-gnu_readlinkat.c,v 1.2 2016/05/31 15:04:51 mef Exp $

* workaround for NetBSD-5.x, readlink is defined as a macro.

--- gnu/readlinkat.c.orig	2015-08-24 19:08:25.000000000 +0900
+++ gnu/readlinkat.c	2016-05-31 23:53:11.000000000 +0900
@@ -69,6 +69,7 @@ rpl_readlinkat (int fd, char const *file
 # define AT_FUNC_POST_FILE_PARAM_DECLS , char *buf, size_t len
 # define AT_FUNC_POST_FILE_ARGS        , buf, len
 # define AT_FUNC_RESULT ssize_t
+# undef readlink
 # include "at-func.c"
 # undef AT_FUNC_NAME
 # undef AT_FUNC_F1
