$NetBSD: patch-src_output.cc,v 1.1 2025/04/09 10:43:40 wiz Exp $

From: Bruno Haible <bruno@clisp.org>
Date: Wed, 9 Apr 2025 10:29:19 +0000 (+0200)
Subject: Avoid "-Wundef" warnings in C++ mode on the generated code.
X-Git-Url: https://git.savannah.gnu.org/gitweb/?p=gperf.git;a=commitdiff_plain;h=3bab6ab7bff26bb444722ff9fc1c58b523e9262d

Avoid "-Wundef" warnings in C++ mode on the generated code.

Reported by Heiko Becker <mail@heiko-becker.de> in
<https://lists.gnu.org/archive/html/bug-gperf/2025-04/msg00001.html>
and by Thomas Klausner <wiz@netbsd.org>.

* src/output.cc (Output::output_hash_function): Emit a
'defined __STDC_VERSION__' before the test of __STDC_VERSION__.

--- src/output.cc.orig	2024-11-16 07:11:16.000000000 +0000
+++ src/output.cc
@@ -953,7 +953,7 @@ Output::output_hash_function () const
           /* Pseudo-statement or comment that avoids a compiler warning or
              lint warning.  */
           const char * const fallthrough_marker =
-            "#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (__STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))\n"
+            "#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))\n"
             "      [[fallthrough]];\n"
             "#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)\n"
             "      __attribute__ ((__fallthrough__));\n"
