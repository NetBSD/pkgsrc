$NetBSD: patch-mozilla_gfx_thebes_gfxFont.cpp,v 1.1 2021/11/18 15:33:16 nia Exp $

Add an explicit template instantiation to make it work
with newer gcc (older gcc did not create specialized inline
clones).

--- mozilla/gfx/thebes/gfxFont.cpp.orig	2018-07-09 19:54:37.000000000 +0000
+++ mozilla/gfx/thebes/gfxFont.cpp
@@ -2614,6 +2614,18 @@ gfxFont::GetShapedWord(DrawTarget *aDraw
     return sw;
 }
 
+template
+gfxShapedWord*
+gfxFont::GetShapedWord(DrawTarget *aDrawTarget,
+                       const uint8_t *aText,
+                       uint32_t    aLength,
+                       uint32_t    aHash,
+                       Script      aRunScript,
+                       bool        aVertical,
+                       int32_t     aAppUnitsPerDevUnit,
+                       uint32_t    aFlags,
+                       gfxTextPerfMetrics *aTextPerf GFX_MAYBE_UNUSED);
+
 bool
 gfxFont::CacheHashEntry::KeyEquals(const KeyTypePointer aKey) const
 {
