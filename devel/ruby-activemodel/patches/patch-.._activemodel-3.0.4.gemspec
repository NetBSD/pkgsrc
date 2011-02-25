$NetBSD: patch-.._activemodel-3.0.4.gemspec,v 1.1.2.2 2011/02/25 10:50:46 tron Exp $

--- ../activemodel-3.0.4.gemspec.orig	2011-02-09 02:59:50.000000000 +0000
+++ ../activemodel-3.0.4.gemspec
@@ -40,7 +40,7 @@ dependencies: 
   requirement: &id002 !ruby/object:Gem::Requirement 
     none: false
     requirements: 
-    - - ~>
+    - - >=
       - !ruby/object:Gem::Version 
         hash: 15
         segments: 
