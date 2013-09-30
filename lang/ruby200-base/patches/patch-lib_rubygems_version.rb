$NetBSD: patch-lib_rubygems_version.rb,v 1.2 2013/09/30 03:15:45 taca Exp $

A fix for CVE-2013-4363.

--- lib/rubygems/version.rb.orig	2012-11-29 06:52:18.000000000 +0000
+++ lib/rubygems/version.rb
@@ -147,8 +147,8 @@ class Gem::Version
 
   # FIX: These are only used once, in .correct?. Do they deserve to be
   # constants?
-  VERSION_PATTERN = '[0-9]+(\.[0-9a-zA-Z]+)*' # :nodoc:
-  ANCHORED_VERSION_PATTERN = /\A\s*(#{VERSION_PATTERN})*\s*\z/ # :nodoc:
+  VERSION_PATTERN = '[0-9]+(\.[0-9a-zA-Z]+)*(-[0-9A-Za-z-]+(\.[0-9A-Za-z-]+)*)?' # :nodoc:
+  ANCHORED_VERSION_PATTERN = /\A\s*(#{VERSION_PATTERN})?\s*\z/ # :nodoc:
 
   ##
   # A string representation of this Version.
