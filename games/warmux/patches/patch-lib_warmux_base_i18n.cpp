$NetBSD: patch-lib_warmux_base_i18n.cpp,v 1.1 2013/04/29 21:31:10 joerg Exp $

--- lib/warmux/base/i18n.cpp.orig	2013-04-29 19:41:28.000000000 +0000
+++ lib/warmux/base/i18n.cpp
@@ -23,6 +23,7 @@
 #include <WARMUX_i18n.h>
 #include <WARMUX_error.h>
 #include <string>
+#include <locale.h>
 #include <stdio.h>
 #include <stdarg.h>
 #include <stdlib.h>
