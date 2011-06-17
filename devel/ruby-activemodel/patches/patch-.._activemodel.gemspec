$NetBSD: patch-.._activemodel.gemspec,v 1.5 2011/06/17 13:50:48 taca Exp $

Allow depending later version gem of builder.

--- ../activemodel-3.0.9.gemspec.orig	2011-06-08 12:56:25.000000000 +0000
+++ ../activemodel-3.0.9.gemspec
@@ -40,7 +40,7 @@ dependencies: 
   requirement: &id002 !ruby/object:Gem::Requirement 
     none: false
     requirements: 
-    - - ~>
+    - - >=
       - !ruby/object:Gem::Version 
         hash: 15
         segments: 
