$NetBSD: patch-ext_phar_phar_phar.php,v 1.2 2025/02/08 02:57:59 taca Exp $

* Fix shbang line.

--- ext/phar/phar/phar.php.orig	2014-11-12 13:52:21.000000000 +0000
+++ ext/phar/phar/phar.php
@@ -1,4 +1,4 @@
-#!/usr/local/bin/php
+#!@PREFIX@/bin/php@PHP_VER@
 <?php
 
 /** @file phar.php
