$NetBSD: patch-stlhelp.h,v 1.1 2011/12/06 19:51:07 joerg Exp $

--- stlhelp.h.orig	2011-12-06 17:03:41.000000000 +0000
+++ stlhelp.h
@@ -19,6 +19,8 @@
 #ifndef _STLHELP_H_
 #define _STLHELP_H_
 
+#include <cstring>
+
 struct eqstr
 {
 	bool operator()(const char* s1, const char* s2) const
