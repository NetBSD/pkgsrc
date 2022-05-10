$NetBSD: patch-config-scripts_cups-compiler.m4,v 1.4 2022/05/10 20:47:37 markd Exp $

Disable SSP checks, leave pkgsrc to enable/disable it.
PIE needs to be tested with linking.

--- config-scripts/cups-compiler.m4.orig	2022-01-27 11:11:42.000000000 +0000
+++ config-scripts/cups-compiler.m4
@@ -131,14 +131,14 @@ AS_IF([test -n "$GCC"], [
     OLDCFLAGS="$CFLAGS"
     CFLAGS="$CFLAGS -fstack-protector-strong"
     AC_LINK_IFELSE([AC_LANG_PROGRAM()], [
-	OPTIM="$OPTIM -fstack-protector-strong"
+	: OPTIM="$OPTIM -fstack-protector-strong"
 	AC_MSG_RESULT([yes])
     ], [
 	AC_MSG_RESULT([no])
 	AC_MSG_CHECKING([whether compiler supports -fstack-protector])
 	CFLAGS="$OLDCFLAGS -fstack-protector"
 	AC_LINK_IFELSE([AC_LANG_PROGRAM()], [
-	    OPTIM="$OPTIM -fstack-protector"
+	    : OPTIM="$OPTIM -fstack-protector"
 	    AC_MSG_RESULT([yes])
 	], [
 	    AC_MSG_RESULT([no])
@@ -164,7 +164,7 @@ AS_IF([test -n "$GCC"], [
 	    ])
 	], [*], [
 	    CFLAGS="$CFLAGS -fPIE -pie"
-	    AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [
+	    AC_LINK_IFELSE([AC_LANG_PROGRAM()], [
 		PIEFLAGS="-fPIE -pie"
 		AC_MSG_RESULT([yes])
 	    ], [
