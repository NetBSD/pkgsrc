$NetBSD: patch-connectivity_source_parse_sqlbison.y,v 1.1 2014/06/01 14:31:08 ryoon Exp $

--- connectivity/source/parse/sqlbison.y.orig	2014-04-30 19:49:45.000000000 +0000
+++ connectivity/source/parse/sqlbison.y
@@ -46,6 +46,10 @@
 #include <rtl/ustrbuf.hxx>
 #include <sal/macros.h>
 
+#if defined(__FreeBSD__)
+#undef _Noreturn
+#endif
+
 #if defined __SUNPRO_CC
 #pragma disable_warn
 #elif defined _MSC_VER
