$NetBSD: patch-qb_config.libs.sh,v 1.3 2018/12/21 15:10:51 nia Exp $

Try regular sort on SunOS.

--- qb/config.libs.sh.orig	2018-10-06 22:00:31.000000000 +0000
+++ qb/config.libs.sh
@@ -40,8 +40,6 @@ elif [ "$OS" = 'Win32' ]; then
    DYLIB=
 elif [ "$OS" = 'Cygwin' ]; then
    die 1 'Error: Cygwin is not a supported platform. See https://bot.libretro.com/docs/compilation/windows/'
-elif [ "$OS" = 'SunOS' ]; then
-   SORT='gsort'
 fi
 
 add_define MAKEFILE DATA_DIR "$SHARE_DIR"
