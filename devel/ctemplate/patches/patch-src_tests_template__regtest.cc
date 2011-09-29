$NetBSD: patch-src_tests_template__regtest.cc,v 1.1 2011/09/29 18:25:13 wiz Exp $

Include header for PATH_MAX.

--- src/tests/template_regtest.cc.orig	2010-04-17 01:46:16.000000000 +0000
+++ src/tests/template_regtest.cc
@@ -42,6 +42,7 @@
 // YY should start with 01 (not 00).  XX can be an arbitrary string.
 
 #include "config_for_unittests.h"
+#include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
