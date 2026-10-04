$NetBSD: patch-lib_LcovUtil_Makefile.PL,v 1.1 2026/10/04 10:06:14 wiz Exp $

Fix build on NetBSD.
https://github.com/linux-test-project/lcov/issues/552

--- lib/LcovUtil/Makefile.PL.orig	2026-10-04 08:54:16.488088210 +0000
+++ lib/LcovUtil/Makefile.PL
@@ -191,7 +191,7 @@ my $cxx_runtime_flags = '';
     # Look for libc++ as well as libstdc++: clang spells the option the same
     # way but may be using libc++ instead, in which case that is the library to
     # ask about.
-    if ($find_lib->('libstdc++.a', 'libc++.a') &&
+    if (0 && $find_lib->('libstdc++.a', 'libc++.a') &&
         $can_link->('-static-libstdc++')) {
         $cxx_runtime_flags = ' -static-libstdc++';
     } else {
