$NetBSD: patch-flim-pkg.el,v 1.1 2023/09/03 14:58:38 mef Exp $

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./flim-pkg.el	1970-01-01 09:00:00.000000000 +0900
+++ ././flim-pkg.el	2018-07-29 22:48:22.274683207 +0900
@@ -0,0 +1,3 @@
+(define-package "flim" "1.14.9"
+  "A library to provide basic features about message representation or encoding."
+  '((apel "10.8")))
