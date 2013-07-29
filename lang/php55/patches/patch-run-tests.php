$NetBSD: patch-run-tests.php,v 1.1 2013/07/29 16:41:02 taca Exp $

Use proper shbang line.

--- run-tests.php.orig	2012-05-03 17:10:43.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
