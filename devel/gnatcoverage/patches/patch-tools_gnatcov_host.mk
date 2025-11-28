$NetBSD: patch-tools_gnatcov_host.mk,v 1.1 2025/11/28 21:03:12 dkazankov Exp $

Add NetBSD support

--- tools/gnatcov/host.mk.orig	2025-06-02 17:05:39.000000000 +0300
+++ tools/gnatcov/host.mk
@@ -15,6 +15,12 @@
 exeext=
 endif
 
+ifneq (,$(filter NetBSD, $(HOST_UNAME)))
+HOST_OS=bsd
+LN_S=ln -sf
+exeext=
+endif
+
 RM=rm -f
 CP=cp -pf
 MKDIR=mkdir -p
