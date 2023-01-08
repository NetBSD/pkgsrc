$NetBSD: patch-m4_erlang-extra.m4,v 1.2 2023/01/08 16:19:05 gdt Exp $

Fix portability of configure script.

https://github.com/processone/ejabberd/pull/3970

--- m4/erlang-extra.m4.orig	2022-05-06 13:12:22.000000000 +0000
+++ m4/erlang-extra.m4
@@ -75,7 +75,7 @@ EOF
 	if test "x`cat conftest.out`" != "xok"; then
 	   AC_MSG_RESULT([failed])
 	   X="`cat conftest.out`"
-	   if test "[$3]" == "warn"; then
+	   if test "[$3]" = "warn"; then
 	      AC_MSG_WARN([$X])
 	   else
 	      AC_MSG_FAILURE([$X])
