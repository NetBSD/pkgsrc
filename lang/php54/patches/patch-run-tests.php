$NetBSD: patch-run-tests.php,v 1.1 2012/06/16 05:21:55 taca Exp $

--- run-tests.php.orig	2012-05-03 17:10:43.000000000 +0000
+++ run-tests.php
@@ -1,4 +1,4 @@
-#!/usr/bin/php
+#!@PREFIX@/bin/php
 <?php
 /*
    +----------------------------------------------------------------------+
