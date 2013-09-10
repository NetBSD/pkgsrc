$NetBSD: patch-lib_rubygems_version.rb,v 1.1 2013/09/10 16:26:31 taca Exp $

A fix for CVE-2013-4287.

--- lib/rubygems/version.rb.orig	2012-11-29 06:52:18.000000000 +0000
+++ lib/rubygems/version.rb
@@ -147,7 +147,7 @@ class Gem::Version
 
   # FIX: These are only used once, in .correct?. Do they deserve to be
   # constants?
-  VERSION_PATTERN = '[0-9]+(\.[0-9a-zA-Z]+)*' # :nodoc:
+  VERSION_PATTERN = '[0-9]+(\.[0-9a-zA-Z]+)*(-[0-9A-Za-z-]+(\.[0-9A-Za-z-]+)*)?' # :nodoc:
   ANCHORED_VERSION_PATTERN = /\A\s*(#{VERSION_PATTERN})*\s*\z/ # :nodoc:
 
   ##
