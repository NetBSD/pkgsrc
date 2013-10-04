$NetBSD: patch-tests_test__connect__delay.cpp,v 1.3 2013/10/04 18:36:54 joerg Exp $

--- tests/test_connect_delay.cpp.orig	2013-10-02 11:20:19.000000000 +0000
+++ tests/test_connect_delay.cpp
@@ -23,6 +23,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <string>
+#include <time.h>
 
 #undef NDEBUG
 #include <assert.h>
