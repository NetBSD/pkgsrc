$NetBSD: patch-make.lua,v 1.1 2023/03/29 20:27:09 nikita Exp $

Do not generate directories with spaces in the file names.

--- make.lua.orig	2022-09-06 18:48:12 UTC
+++ make.lua
@@ -96,6 +96,5 @@ lm:build 'unit-test' {
 }
 
 lm:default {
-    "bee-test",
-    "unit-test",
+    "all"
 }
