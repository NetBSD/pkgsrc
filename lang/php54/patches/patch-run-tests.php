$NetBSD: patch-run-tests.php,v 1.2 2012/07/20 12:29:05 taca Exp $

Use proper shbang line.

--- run-tests.php.orig	2012-05-03 17:10:43.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
