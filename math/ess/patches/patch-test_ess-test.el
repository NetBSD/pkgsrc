$NetBSD: patch-test_ess-test.el,v 1.1 2026/10/07 19:55:20 markd Exp $

ess-jags-mode in ./obsolete/ since 2026-03-23

--- test/ess-test.el.orig	2026-05-26 14:29:02.000000000 +0000
+++ test/ess-test.el
@@ -36,8 +36,8 @@
 (ert-deftest R-mode ()
   (should (string= 'ess-r-mode (with-temp-buffer (R-mode) major-mode))))
 
-(ert-deftest ess-jags-mode ()
-  (should (string= 'ess-jags-mode (with-temp-buffer (ess-jags-mode) major-mode))))
+;;(ert-deftest ess-jags-mode ()
+;;  (should (string= 'ess-jags-mode (with-temp-buffer (ess-jags-mode) major-mode))))
 
 (ert-deftest ess-bugs-mode ()
   (should (string= 'ess-bugs-mode (with-temp-buffer (ess-bugs-mode) major-mode))))
