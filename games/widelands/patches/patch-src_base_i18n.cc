$NetBSD: patch-src_base_i18n.cc,v 1.1 2019/12/19 22:16:34 joerg Exp $

--- src/base/i18n.cc.orig	2019-12-19 15:58:00.820559242 +0000
+++ src/base/i18n.cc
@@ -19,10 +19,7 @@
 
 #include "base/i18n.h"
 
-#ifdef __FreeBSD__
 #include <clocale>
-#endif
-
 #include <cstdlib>
 #include <map>
 #include <utility>
