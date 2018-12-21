$NetBSD: patch-tests_runtests.sh,v 1.1 2018/12/21 12:35:38 leot Exp $

`export -p' also exports make(1) variables that contains `.', e.g.
`.MAKE.ENV.LEVEL'.  As part of `. ./env.out' this lead to failure because
variable with `.' are not valid is sh(1) context.
Filter `export -p' output to avoid that.

--- tests/runtests.sh.orig	2018-09-23 09:24:46.000000000 +0000
+++ tests/runtests.sh
@@ -64,7 +64,7 @@ cp $TYPESDB test-repository/types.db
 
 echo "======================================== repository search path ..."
 if test -z "$MSYSTEM"; then
-  export -p >./env.out
+  export -p | sed -ne '/export [^.]*=/p' >./env.out
   unset CHICKEN_REPOSITORY_PATH
   $interpret -s repository-path-default.scm
   . ./env.out
