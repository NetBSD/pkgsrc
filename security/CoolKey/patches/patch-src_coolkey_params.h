$NetBSD: patch-src_coolkey_params.h,v 1.1 2013/04/29 21:31:12 joerg Exp $

--- src/coolkey/params.h.orig	2013-04-29 20:24:44.000000000 +0000
+++ src/coolkey/params.h
@@ -20,6 +20,7 @@
 #ifndef COOLKEY_PARAMS_H
 #define COOLKEY_PARAMS_H
 
+#include <cstdlib>
 
 class Params {
 
