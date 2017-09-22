$NetBSD: patch-conf_Unix.mk,v 1.1 2017/09/22 22:00:57 wiedi Exp $

Don't overwrite LDFLAGS
--- conf/Unix.mk.orig	2017-04-03 19:42:14.000000000 +0000
+++ conf/Unix.mk
@@ -53,7 +53,7 @@ LDDLLOUT = -o
 
 # Static linker.
 LD = gcc
-LDFLAGS = 
+#LDFLAGS = 
 LDOUT = -o 
 
 # C# compiler; we assume usage of Mono.
