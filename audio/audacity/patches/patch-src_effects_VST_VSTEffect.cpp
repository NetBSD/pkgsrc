$NetBSD: patch-src_effects_VST_VSTEffect.cpp,v 1.1 2015/04/20 13:38:23 rodent Exp $

Some platforms don't have RTLD_DEEPBIND.

--- src/effects/VST/VSTEffect.cpp.orig	2015-03-02 01:06:58.000000000 +0000
+++ src/effects/VST/VSTEffect.cpp
@@ -2609,7 +2609,11 @@ bool VSTEffect::Load()
    // symbols.
    //
    // Once we define a proper external API, the flags can be removed.
+# if defined(RTLD_DEEPBIND)
    void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
+# else
+   void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL);
+# endif
    if (!lib) 
    {
       return false;
