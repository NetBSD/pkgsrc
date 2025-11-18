$NetBSD: patch-config-scripts_cups-compiler.m4,v 1.5 2025/11/18 17:38:35 nia Exp $

Disable hardening, leave pkgsrc to enable/disable it.
PIE needs to be tested with linking.

--- config-scripts/cups-compiler.m4.orig	2025-09-11 16:53:21.000000000 +0000
+++ config-scripts/cups-compiler.m4
@@ -108,10 +108,6 @@ AS_IF([test -n "$GCC"], [
     ], [echo "$CXXFLAGS $CFLAGS" | grep -q _FORTIFY_SOURCE], [
         # Don't add _FORTIFY_SOURCE if it is already there
     ], [
-	# Otherwise use the Fortify enhancements to catch any unbounded
-	# string operations...
-	CFLAGS="$CFLAGS -D_FORTIFY_SOURCE=3"
-	CXXFLAGS="$CXXFLAGS -D_FORTIFY_SOURCE=3"
     ])
 
     # Default optimization options...
@@ -133,14 +129,14 @@ AS_IF([test -n "$GCC"], [
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
@@ -166,7 +162,7 @@ AS_IF([test -n "$GCC"], [
 	    ])
 	], [*], [
 	    CFLAGS="$CFLAGS -fPIE -pie"
-	    AC_COMPILE_IFELSE([AC_LANG_PROGRAM()], [
+	    AC_LINK_IFELSE([AC_LANG_PROGRAM()], [
 		PIEFLAGS="-fPIE -pie"
 		AC_MSG_RESULT([yes])
 	    ], [
