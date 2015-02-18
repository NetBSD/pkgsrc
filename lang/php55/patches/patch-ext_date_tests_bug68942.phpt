$NetBSD: patch-ext_date_tests_bug68942.phpt,v 1.1.2.2 2015/02/18 18:54:20 tron Exp $

Test bug #68942 (Use after free vulnerability in unserialize() with DateTimeZone)

--- ext/date/tests/bug68942.phpt.orig	2015-02-18 02:20:29.000000000 +0000
+++ ext/date/tests/bug68942.phpt
@@ -0,0 +1,9 @@
+--TEST--
+Bug #68942 (Use after free vulnerability in unserialize() with DateTimeZone).
+--FILE--
+<?php
+$data = unserialize('a:2:{i:0;O:12:"DateTimeZone":2:{s:13:"timezone_type";a:2:{i:0;i:1;i:1;i:2;}s:8:"timezone";s:1:"A";}i:1;R:4;}');
+var_dump($data);
+?>
+--EXPECTF--
+Fatal error: DateTimeZone::__wakeup(): Timezone initialization failed in %s/bug68942.php on line %d
