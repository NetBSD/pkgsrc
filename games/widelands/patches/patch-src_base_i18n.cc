$NetBSD: patch-src_base_i18n.cc,v 1.2 2020/07/27 15:21:43 nia Exp $

Include clocale unconditionally.

--- src/base/i18n.cc.orig	2020-07-12 19:33:44.000000000 +0000
+++ src/base/i18n.cc
@@ -19,9 +19,7 @@
 
 #include "base/i18n.h"
 
-#ifdef __FreeBSD__
 #include <clocale>
-#endif
 
 #include <map>
 
