$NetBSD: patch-.._activemodel.gemspec,v 1.1 2011/03/25 08:44:45 taca Exp $

Allow depending later version gem of builder.

--- ../activemodel-3.0.5.gemspec.orig	2011-02-28 08:08:29.000000000 +0000
+++ ../activemodel-3.0.5.gemspec
@@ -40,7 +40,7 @@ dependencies: 
   requirement: &id002 !ruby/object:Gem::Requirement 
     none: false
     requirements: 
-    - - ~>
+    - - >=
       - !ruby/object:Gem::Version 
         hash: 15
         segments: 
