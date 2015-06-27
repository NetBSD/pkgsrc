$NetBSD: patch-src_lib_FHPath.h,v 1.1 2015/06/27 18:41:40 joerg Exp $

--- src/lib/FHPath.h.orig	2015-06-27 14:05:28.000000000 +0000
+++ src/lib/FHPath.h
@@ -16,7 +16,7 @@
 namespace libfreehand
 {
 
-class FHTransform;
+struct FHTransform;
 
 class FHPathElement
 {
