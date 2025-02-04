$NetBSD: patch-src_util_Alloca.h,v 1.1 2025/02/04 11:25:45 wiz Exp $

Fix build on NetBSD
https://github.com/wolfpld/vv/pull/11/files

--- src/util/Alloca.h.orig	2024-12-23 10:46:59.000000000 +0000
+++ src/util/Alloca.h
@@ -1,6 +1,6 @@
 #pragma once
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <stdlib.h>
 #else
 #  include <alloca.h>
