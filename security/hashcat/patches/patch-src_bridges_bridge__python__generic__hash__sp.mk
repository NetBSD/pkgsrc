$NetBSD: patch-src_bridges_bridge__python__generic__hash__sp.mk,v 1.2 2025/09/08 15:03:41 adam Exp $

Use correct python-config.

--- src/bridges/bridge_python_generic_hash_sp.mk.orig	2025-08-23 08:43:56.000000000 +0000
+++ src/bridges/bridge_python_generic_hash_sp.mk
@@ -3,13 +3,13 @@ REPORT_MISSING_DLL := false
 
 ifeq ($(BRIDGE_SUFFIX),so)
 ifeq ($(REPORT_MISSING_SO),false)
-PYTHON_CONFIG := $(shell command -v python3-config 2>/dev/null)
+PYTHON_CONFIG := $(shell command -v python${PYVERSSUFFIX}-config 2>/dev/null)
 ifeq ($(PYTHON_CONFIG),)
 	REPORT_MISSING_SO := true
 endif
 endif
 ifeq ($(REPORT_MISSING_SO),false)
-PYTHON_CFLAGS := $(shell python3-config --includes 2>/dev/null)
+PYTHON_CFLAGS := $(shell python${PYVERSSUFFIX}-config --includes 2>/dev/null)
 ifeq ($(strip $(PYTHON_CFLAGS)),)
 	REPORT_MISSING_SO := true
 endif
