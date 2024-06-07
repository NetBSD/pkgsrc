$NetBSD: patch-build_php.m4,v 1.1 2024/06/07 13:54:25 taca Exp $

Do not include "PKG_CONFIG*" in CONFIGURE_OPTIONS.

--- build/php.m4.orig	2024-06-05 05:51:57.000000000 +0000
+++ build/php.m4
@@ -2152,6 +2152,10 @@ EOF
    else
     break
    fi
+   case "$CURRENT_ARG" in
+       \'PKG_CONFIG\=*)	CURRENT_ARG="'PKG_CONFIG=@TOOLS_PATH.pkg-config@'";;
+       \'PKG_CONFIG_LIBDIR\=*)	CURRENT_ARG="'PKG_CONFIG_LIBDIR=@PHP_PKGCONFIG_PATH@'";;
+   esac
    AS_ECHO(["$CURRENT_ARG \\"]) >>$1
    CONFIGURE_OPTIONS="$CONFIGURE_OPTIONS $CURRENT_ARG"
   done
