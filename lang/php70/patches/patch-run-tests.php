$NetBSD: patch-run-tests.php,v 1.1 2015/12/06 15:17:31 taca Exp $

--- run-tests.php.orig	2015-06-23 17:33:33.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/env php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
