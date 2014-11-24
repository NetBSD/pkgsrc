$NetBSD: patch-ext_phar_phar_phar.php,v 1.1 2014/11/24 15:37:08 taca Exp $

--- ext/phar/phar/phar.php.orig	2014-11-12 13:52:21.000000000 +0000
+++ ext/phar/phar/phar.php
@@ -1,4 +1,4 @@
-#!/usr/local/bin/php
+#!@PREFIX@/bin/php
 <?php
 
 /** @file phar.php
