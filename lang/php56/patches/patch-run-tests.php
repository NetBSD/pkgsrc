$NetBSD: patch-run-tests.php,v 1.1 2014/11/24 15:37:08 taca Exp $

Use proper shbang line.

--- run-tests.php.orig	2014-11-12 13:52:21.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
