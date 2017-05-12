$NetBSD: patch-m4_fpending.m4,v 1.1 2017/05/12 05:13:43 maya Exp $

try to pickup __fpending from <stdio.h>
DragonflyBSD has one, and a conflicting type.

--- m4/fpending.m4.orig	2005-03-23 00:04:29.000000000 +0000
+++ m4/fpending.m4
@@ -23,6 +23,7 @@ AC_DEFUN([gl_FUNC_FPENDING],
 #     if HAVE_STDIO_EXT_H
 #      include <stdio_ext.h>
 #     endif
+#     include <stdio.h>
 '
   AC_CHECK_DECLS([__fpending], , , $fp_headers)
   if test $ac_cv_func___fpending = no; then
