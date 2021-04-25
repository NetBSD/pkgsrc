$NetBSD: patch-src_configuration.h,v 1.1 2021/04/25 08:04:14 nia Exp $

Add missing include, fixing build with gcc10.

--- src/configuration.h.orig	2020-03-14 14:36:08.000000000 +0000
+++ src/configuration.h
@@ -2,6 +2,7 @@
 #define CONFIGURATION_H
 
 #include <map>
+#include <string>
 
 namespace config
 {
