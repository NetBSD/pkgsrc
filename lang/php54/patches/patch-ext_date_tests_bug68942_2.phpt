$NetBSD: patch-ext_date_tests_bug68942_2.phpt,v 1.1 2015/02/18 11:04:03 sevan Exp $

Test for bug #68942 (Use after free vulnerability in unserialize() with DateTimeZone)

--- ext/date/tests/bug68942_2.phpt.orig	2015-02-18 01:43:49.000000000 +0000
+++ ext/date/tests/bug68942_2.phpt
@@ -0,0 +1,9 @@
+--TEST--
+Bug #68942 (Use after free vulnerability in unserialize() with DateTime).
+--FILE--
+<?php
+$data = unserialize('a:2:{i:0;O:8:"DateTime":3:{s:4:"date";s:26:"2000-01-01 00:00:00.000000";s:13:"timezone_type";a:2:{i:0;i:1;i:1;i:2;}s:8:"timezone";s:1:"A";}i:1;R:5;}');
+var_dump($data);
+?>
+--EXPECTF--
+Fatal error: Invalid serialization data for DateTime object in %s/bug68942_2.php on line %d
