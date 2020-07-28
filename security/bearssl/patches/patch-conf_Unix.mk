$NetBSD: patch-conf_Unix.mk,v 1.3 2020/07/28 08:49:54 wiz Exp $

Don't overwrite LDFLAGS

--- conf/Unix.mk.orig	2018-08-14 20:41:54.000000000 +0000
+++ conf/Unix.mk
@@ -38,7 +38,7 @@ MKDIR = mkdir -p
 
 # C compiler and flags.
 CC = cc
-CFLAGS = -W -Wall -Os -fPIC
+CFLAGS += -W -Wall -Os -fPIC
 CCOUT = -c -o 
 
 # Static library building tool.
@@ -48,12 +48,12 @@ AROUT =
 
 # DLL building tool.
 LDDLL = cc
-LDDLLFLAGS = -shared
+LDDLLFLAGS = -shared ${LDFLAGS}
 LDDLLOUT = -o 
 
 # Static linker.
 LD = cc
-LDFLAGS = 
+#LDFLAGS = 
 LDOUT = -o 
 
 # C# compiler; we assume usage of Mono.
