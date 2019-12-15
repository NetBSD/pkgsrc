$NetBSD: patch-ext_phar_phar_phar.php,v 1.1 2019/12/15 17:56:34 taca Exp $

Prepare for shbang line replace.

--- ext/phar/phar/phar.php.orig	2015-06-23 17:33:33.000000000 +0000
+++ ext/phar/phar/phar.php
@@ -1,4 +1,4 @@
-#!/usr/local/bin/php
+#!@PREFIX@/bin/php
 <?php
 
 /** @file phar.php
