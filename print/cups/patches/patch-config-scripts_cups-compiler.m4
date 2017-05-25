$NetBSD: patch-config-scripts_cups-compiler.m4,v 1.3 2017/05/25 12:11:55 jperkin Exp $

Some builds of gcc seem to support this for compiling but then fail during
linking with undefined reference to `__stack_chk_fail_local'

PIE needs to be tested with linking.

--- config-scripts/cups-compiler.m4.orig	2017-03-28 18:26:53.000000000 +0000
+++ config-scripts/cups-compiler.m4
@@ -111,12 +111,13 @@ if test -n "$GCC"; then
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
@@ -133,7 +134,7 @@ if test -n "$GCC"; then
 		case "$uname" in
 			Darwin*)
 				CFLAGS="$CFLAGS -fPIE -Wl,-pie"
-				AC_TRY_COMPILE(,,[
+				AC_TRY_LINK(,,[
 					PIEFLAGS="-fPIE -Wl,-pie"
 					AC_MSG_RESULT(yes)],
 					AC_MSG_RESULT(no))
@@ -141,7 +142,7 @@ if test -n "$GCC"; then
 
 			*)
 				CFLAGS="$CFLAGS -fPIE -pie"
-				AC_TRY_COMPILE(,,[
+				AC_TRY_LINK(,,[
 					PIEFLAGS="-fPIE -pie"
 					AC_MSG_RESULT(yes)],
 					AC_MSG_RESULT(no))
