$NetBSD: patch-src_support_solaris_xlocale.cpp,v 1.2 2022/08/12 08:43:58 pin Exp $

don't try to use sys/localedef.h on SunOS if nonexistent
OpenIndiana doesn't seem to ship the header.
Userland shouldn't use it, according to Garrett D'Amore:
https://illumos.topicbox.com/groups/developer/T6cfd2e6cd87f3485-M30dac0cb6fffae62ef45b9a8

--- src/support/solaris/xlocale.cpp.orig	2022-06-22 16:46:24.000000000 +0000
+++ src/support/solaris/xlocale.cpp
@@ -6,7 +6,7 @@
 //
 //===----------------------------------------------------------------------===//
 
-#ifdef __sun__
+#ifdef(__sun__) && __has_include(<sys/localedef.h>)
 
 #include "__support/solaris/xlocale.h"
 #include <stdarg.h>
