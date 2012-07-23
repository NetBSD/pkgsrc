$NetBSD: patch-run-tests.php,v 1.1.2.1 2012/07/23 18:24:34 tron Exp $

Use proper shbang line.

--- run-tests.php.orig	2012-05-03 17:10:43.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
