$NetBSD: patch-build_php.m4,v 1.1 2024/06/07 13:57:24 taca Exp $

Do not include "PKG_CONFIG*" in CONFIGURE_OPTIONS.

--- build/php.m4.orig	2024-06-04 14:53:17.000000000 +0000
+++ build/php.m4
@@ -2151,6 +2151,10 @@ EOF
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
