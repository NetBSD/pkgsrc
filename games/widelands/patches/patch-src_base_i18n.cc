$NetBSD: patch-src_base_i18n.cc,v 1.3 2024/11/18 07:58:49 wiz Exp $

Include clocale unconditionally.

Undefine any *gettext macros to avoid infinite recursion.

https://github.com/widelands/widelands/issues/6488

--- src/base/i18n.cc.orig	2024-10-30 12:47:18.000000000 +0000
+++ src/base/i18n.cc
@@ -46,6 +46,12 @@
 #endif
 #endif
 
+// If eg. pgettext_expr happens to be a macro back to pgettext, we need
+// to clear these to avoid infinite recursion.
+#undef pgettext
+#undef ngettext
+#undef npgettext
+
 namespace i18n {
 
 /// A stack of textdomains. On entering a new textdomain, the old one gets
