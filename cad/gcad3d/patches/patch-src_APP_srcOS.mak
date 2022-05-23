$NetBSD: patch-src_APP_srcOS.mak,v 1.1 2022/05/23 19:10:03 plunky Exp $

always include unix files

--- src/APP/srcOS.mak.orig	2022-03-04 12:26:39.000000000 +0000
+++ src/APP/srcOS.mak
@@ -4,8 +4,6 @@
   SRCOS = ../ut/os_uix.c ../ut/ut_os_aix.c ../ut/ctrl_os_aix.c
 endif
 
-ifeq "$(hTyp)" "Linux_x86_64"
   SRCOS = ../ut/os_uix.c ../ut/ut_os_aix.c ../ut/ctrl_os_aix.c
-endif
 
 # eof
