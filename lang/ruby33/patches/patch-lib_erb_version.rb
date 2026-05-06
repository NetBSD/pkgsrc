$NetBSD: patch-lib_erb_version.rb,v 1.1 2026/05/06 05:28:23 taca Exp $

Update to erb 4.0.3.1 to fix CVE-2026-41316.

--- lib/erb/version.rb.orig	2026-03-26 00:05:04.000000000 +0000
+++ lib/erb/version.rb
@@ -1,5 +1,5 @@
 # frozen_string_literal: true
 class ERB
-  VERSION = '4.0.3'
+  VERSION = '4.0.3.1'
   private_constant :VERSION
 end
