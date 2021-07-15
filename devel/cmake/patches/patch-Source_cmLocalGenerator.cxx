$NetBSD: patch-Source_cmLocalGenerator.cxx,v 1.1 2021/07/15 21:10:53 jperkin Exp $

Disable additional -arch flags on macOS.

--- Source/cmLocalGenerator.cxx.orig	2021-06-21 15:23:19.000000000 +0000
+++ Source/cmLocalGenerator.cxx
@@ -97,7 +97,7 @@ cmLocalGenerator::cmLocalGenerator(cmGlo
 
   this->AliasTargets = makefile->GetAliasTargets();
 
-  this->EmitUniversalBinaryFlags = true;
+  this->EmitUniversalBinaryFlags = false;
   this->BackwardsCompatibility = 0;
   this->BackwardsCompatibilityFinal = false;
 
