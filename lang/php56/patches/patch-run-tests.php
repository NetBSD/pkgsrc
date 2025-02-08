$NetBSD: patch-run-tests.php,v 1.2 2025/02/08 02:57:59 taca Exp $

Use proper shbang line.

--- run-tests.php.orig	2014-11-12 13:52:21.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php@PHP_VER@
 <?php
 /*
    +----------------------------------------------------------------------+
