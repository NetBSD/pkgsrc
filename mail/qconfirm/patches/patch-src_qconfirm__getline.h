$NetBSD: patch-src_qconfirm__getline.h,v 1.1 2019/07/09 18:23:15 schmonz Exp $

Rename local getline() to avoid duplicating a system-provided definition.

--- src/qconfirm_getline.h.orig	2004-12-12 16:57:17.000000000 +0000
+++ src/qconfirm_getline.h
@@ -1 +1 @@
-extern int getline();
+extern int qconfirm_getline();
