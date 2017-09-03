$NetBSD: patch-config-scripts_cups-compiler.m4,v 1.4 2017/09/03 11:30:54 leot Exp $

Some builds of gcc seem to support this for compiling but then fail during
linking with undefined reference to `__stack_chk_fail_local'

PIE needs to be tested with linking.

--- config-scripts/cups-compiler.m4.orig	2017-06-30 15:44:38.000000000 +0000
+++ config-scripts/cups-compiler.m4
@@ -115,12 +115,13 @@ if test -n "$GCC"; then
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
@@ -137,7 +138,7 @@ if test -n "$GCC"; then
 		case "$host_os_name" in
 			darwin*)
 				CFLAGS="$CFLAGS -fPIE -Wl,-pie"
-				AC_TRY_COMPILE(,,[
+				AC_TRY_LINK(,,[
 					PIEFLAGS="-fPIE -Wl,-pie"
 					AC_MSG_RESULT(yes)],
 					AC_MSG_RESULT(no))
@@ -145,7 +146,7 @@ if test -n "$GCC"; then
 
 			*)
 				CFLAGS="$CFLAGS -fPIE -pie"
-				AC_TRY_COMPILE(,,[
+				AC_TRY_LINK(,,[
 					PIEFLAGS="-fPIE -pie"
 					AC_MSG_RESULT(yes)],
 					AC_MSG_RESULT(no))
