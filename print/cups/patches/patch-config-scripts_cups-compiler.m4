$NetBSD: patch-config-scripts_cups-compiler.m4,v 1.1 2015/01/02 02:03:42 christos Exp $

Some builds of gcc seem to support this for compiling but then fail during
linking with undefined reference to `__stack_chk_fail_local'

--- config-scripts/cups-compiler.m4.orig	2014-08-28 08:55:52.000000000 -0400
+++ config-scripts/cups-compiler.m4	2014-12-24 14:20:36.000000000 -0500
@@ -113,12 +113,13 @@
 	AC_MSG_CHECKING(whether compiler supports -fstack-protector)
 	OLDCFLAGS="$CFLAGS"
 	CFLAGS="$CFLAGS -fstack-protector"
-	AC_TRY_LINK(,,
+	AC_TRY_LINK(, [return 0;],
 		if test "x$LSB_BUILD" = xy; then
 			# Can't use stack-protector with LSB binaries...
 			OPTIM="$OPTIM -fno-stack-protector"
 		else
 			OPTIM="$OPTIM -fstack-protector"
+			LIBS="$LIBS $LIBS_SSP"
 		fi
 		AC_MSG_RESULT(yes),
 		AC_MSG_RESULT(no))
