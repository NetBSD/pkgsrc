$NetBSD: patch-run-tests.php,v 1.1 2016/08/04 14:09:03 jdolecek Exp $

--- run-tests.php.orig	2015-06-23 17:33:33.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
