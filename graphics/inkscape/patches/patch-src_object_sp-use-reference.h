$NetBSD: patch-src_object_sp-use-reference.h,v 1.1 2021/08/20 11:40:15 nia Exp $

Fix build error on NetBSD 9.x.
https://gitlab.com/inkscape/inkscape/-/merge_requests/3345

--- src/object/sp-use-reference.h.orig	2021-05-17 19:25:49.000000000 +0000
+++ src/object/sp-use-reference.h
@@ -14,11 +14,10 @@
 
 #include "sp-item.h"
 #include "uri-references.h"
+#include "display/curve.h"
 
 #include <memory>
 
-class SPCurve;
-
 namespace Inkscape {
 namespace XML {
 class Node;
