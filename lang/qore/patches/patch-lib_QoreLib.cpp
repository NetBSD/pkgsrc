$NetBSD: patch-lib_QoreLib.cpp,v 1.1 2016/03/09 21:32:41 nros Exp $
* Fix build with open/libressl releases without evp_SHA
  https://github.com/qorelanguage/qore/commit/fc181070ad1afbf49af2e8fc968b97328d690a86
--- lib/QoreLib.cpp.orig	2016-03-09 20:30:24.000000000 +0000
+++ lib/QoreLib.cpp
@@ -185,6 +185,15 @@ const qore_option_s qore_option_list_l[]
      false
 #endif
    },
+   { QORE_OPT_SHA,
+     "HAVE_SHA",
+     QO_ALGORITHM,
+#ifdef HAVE_OPENSSL_SHA
+     true
+#else
+     false
+#endif
+   },
    { QORE_OPT_SHA224,
      "HAVE_SSH224",
      QO_ALGORITHM,
