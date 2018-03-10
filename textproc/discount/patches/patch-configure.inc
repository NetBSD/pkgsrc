$NetBSD: patch-configure.inc,v 1.1 2018/03/10 05:37:44 schmonz Exp $

Fix installed dylib linker path on Darwin.

--- configure.inc.orig	2018-03-02 22:52:05.000000000 +0000
+++ configure.inc
@@ -1362,7 +1362,7 @@ FULLNAME=\$LIBNAME
 
 case "\$ACTION" in
 make)   FLAGS="$AC_CFLAGS -dynamiclib"
-	VFLAGS="-current_version \$VERSION -compatibility_version \$MAJOR"
+	VFLAGS="-install_name $AC_LIBDIR/\$LIBNAME -current_version \$VERSION -compatibility_version \$MAJOR"
 
 	rm -f \$LIBRARY
 	if $AC_CC \$FLAGS \$VFLAGS -o \$FULLNAME "\$@"; then
