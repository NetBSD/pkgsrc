$NetBSD: patch-build_common.mk,v 1.1 2015/05/23 06:43:00 kefren Exp $

Build with mcs

--- build/common.mk.orig	2015-05-22 19:54:31.000000000 +0300
+++ build/common.mk	2015-05-22 19:54:38.000000000 +0300
@@ -9,7 +9,7 @@
 
 CC=gcc
 LD=ld
-CSC=gmcs
+CSC=mcs
 CSC_DEBUG=-d:DEBUG -debug+
 RECURSIVE_TARGETS = check clean install uninstall
 
