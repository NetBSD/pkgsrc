$NetBSD: patch-src_format.h,v 1.1 2026/06/28 19:59:00 wiz Exp $

Fix build with latest boost.

--- src/format.h.orig	2026-06-28 19:48:23.492168946 +0000
+++ src/format.h
@@ -42,6 +42,7 @@
 #ifndef _FORMAT_H
 #define _FORMAT_H
 
+#include <boost/scoped_ptr.hpp>
 #include "expr.h"
 #include "unistring.h"
 
