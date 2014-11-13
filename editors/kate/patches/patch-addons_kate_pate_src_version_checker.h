$NetBSD: patch-addons_kate_pate_src_version_checker.h,v 1.1 2014/11/13 20:10:09 markd Exp $

--- addons/kate/pate/src/version_checker.h.orig	2014-10-26 20:17:55.000000000 +0000
+++ addons/kate/pate/src/version_checker.h
@@ -24,6 +24,13 @@
 # include <QtCore/QStringList>
 # include <QtCore/QtGlobal>
 
+# ifdef major
+#  undef major
+# endif
+# ifdef minor
+#  undef minor
+# endif
+
 namespace Pate {
 
 /**
