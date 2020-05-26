$NetBSD: patch-config-scripts_cups-compiler.m4,v 1.3 2020/05/26 08:36:56 triaxx Exp $

Disable SSP checks, leave pkgsrc to enable/disable it.
PIE needs to be tested with linking.

--- config-scripts/cups-compiler.m4.orig	2017-11-01 14:57:53.000000000 +0000
+++ config-scripts/cups-compiler.m4
@@ -129,12 +129,13 @@ if test -n "$GCC"; then
 	AC_MSG_CHECKING(whether compiler supports -fstack-protector)
 	OLDCFLAGS="$CFLAGS"
 	CFLAGS="$CFLAGS -fstack-protector"
-	AC_TRY_LINK(,,
+	AC_TRY_LINK(, [return 0;],
 		if test "x$LSB_BUILD" = xy; then
 			# Can't use stack-protector with LSB binaries...
-			OPTIM="$OPTIM -fno-stack-protector"
+			: OPTIM="$OPTIM -fno-stack-protector"
 		else
-			OPTIM="$OPTIM -fstack-protector"
+			: OPTIM="$OPTIM -fstack-protector"
+			: LIBS="$LIBS $LIBS_SSP"
 		fi
 		AC_MSG_RESULT(yes),
 		AC_MSG_RESULT(no))
@@ -151,7 +152,7 @@ if test -n "$GCC"; then
 		case "$host_os_name" in
 			darwin*)
 				CFLAGS="$CFLAGS -fPIE -Wl,-pie"
-				AC_TRY_COMPILE(,,[
+				AC_TRY_LINK(,,[
 					PIEFLAGS="-fPIE -Wl,-pie"
 					AC_MSG_RESULT(yes)],
 					AC_MSG_RESULT(no))
@@ -159,7 +160,7 @@ if test -n "$GCC"; then
 
 			*)
 				CFLAGS="$CFLAGS -fPIE -pie"
-				AC_TRY_COMPILE(,,[
+				AC_TRY_LINK(,,[
 					PIEFLAGS="-fPIE -pie"
 					AC_MSG_RESULT(yes)],
 					AC_MSG_RESULT(no))
