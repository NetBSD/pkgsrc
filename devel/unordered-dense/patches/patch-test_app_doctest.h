$NetBSD: patch-test_app_doctest.h,v 1.1 2026/09/24 16:16:33 ktnb Exp $

doctest is in its own directory in pkgsrc

--- test/app/doctest.h.orig	2026-09-22 18:30:48.541697319 +0000
+++ test/app/doctest.h
@@ -7,7 +7,7 @@
 #    pragma clang diagnostic push
 #    pragma clang diagnostic ignored "-W#warnings"
 #endif
-#include <doctest.h>
+#include <doctest/doctest.h>
 #if defined(__clang__)
 #    pragma clang diagnostic pop
 #endif
