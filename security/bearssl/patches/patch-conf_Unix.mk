$NetBSD: patch-conf_Unix.mk,v 1.2 2019/01/21 06:59:58 agc Exp $

Don't overwrite LDFLAGS

--- conf/Unix.mk.orig	2018-08-14 13:41:54.000000000 -0700
+++ conf/Unix.mk	2019-01-20 22:50:36.191161113 -0800
@@ -53,7 +53,7 @@
 
 # Static linker.
 LD = cc
-LDFLAGS = 
+#LDFLAGS = 
 LDOUT = -o 
 
 # C# compiler; we assume usage of Mono.
