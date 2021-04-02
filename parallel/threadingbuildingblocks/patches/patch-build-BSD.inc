$NetBSD: patch-build-BSD.inc,v 1.1 2021/04/02 07:59:35 mrg Exp $

Support arm64.

--- build/BSD.inc.orig	2020-07-10 06:18:01.000000000 -0700
+++ build/BSD.inc	2021-04-02 00:55:40.143683568 -0700
@@ -22,6 +22,9 @@
         ifeq ($(shell uname -m),amd64)
                 export arch:=intel64
         endif
+        ifeq ($(shell uname -p),aarch64)
+                export arch:=arm64
+        endif
 endif
 
 ifndef runtime
