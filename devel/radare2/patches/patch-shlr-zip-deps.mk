$NetBSD: patch-shlr-zip-deps.mk,v 1.1 2015/02/27 12:11:20 gdt Exp $

Cherry-picked change from upstream revision c2770de2b8fdaa4ff815dfe30f568aa618f3ac61
"Fix #1667 - Fix --with-syszip"

--- shlr/zip/deps.mk.orig	2014-06-01 15:52:59.000000000 +0000
+++ shlr/zip/deps.mk
@@ -2,7 +2,7 @@
 #LINK+=${STOP}/zip/zip/*.o
 #LINK+=${STOP}/zip/zlib/*.o
 ifeq ($(USE_LIB_ZIP),1)
-LINK=$(LIBZIP)
+LINK+=$(LIBZIP)
 else
 LINK+=../../shlr/zip/librz.a
 endif
