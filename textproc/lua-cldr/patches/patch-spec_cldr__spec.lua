$NetBSD: patch-spec_cldr__spec.lua,v 1.1 2023/04/06 12:05:32 joerg Exp $

From git, fix the assertion to match the actual data.

--- spec/cldr_spec.lua.orig	2023-04-06 11:52:51.710757187 +0000
+++ spec/cldr_spec.lua
@@ -11,7 +11,7 @@ describe('cldr', function ()
   end)
 
   it('should have a bunch of locales', function ()
-    assert.equal(674, Set.len(CLDR.locales))
+    assert.equal(681, Set.len(CLDR.locales))
   end)
 
   it('should have truthy set accessors to locales', function ()
