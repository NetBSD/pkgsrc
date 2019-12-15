$NetBSD: patch-run-tests.php,v 1.1 2019/12/15 17:56:34 taca Exp $

Prepare for shbang line replace.

--- run-tests.php.orig	2018-12-04 16:12:20.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
