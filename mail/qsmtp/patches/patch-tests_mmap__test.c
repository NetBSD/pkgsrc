$NetBSD: patch-tests_mmap__test.c,v 1.1 2020/01/12 23:03:28 joerg Exp $

Find LOCK_* on NetBSD.

--- tests/mmap_test.c.orig	2020-01-11 21:22:55.244319133 +0000
+++ tests/mmap_test.c
@@ -1,3 +1,4 @@
+#define _NETBSD_SOURCE
 #include <mmap.h>
 #include "test_io/testcase_io.h"
 
