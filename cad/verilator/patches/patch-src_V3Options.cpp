$NetBSD: patch-src_V3Options.cpp,v 1.1 2025/12/24 16:52:27 ryoon Exp $

* Use gmake from pkgsrc.

--- src/V3Options.cpp.orig	2025-12-18 08:45:06.787694634 +0000
+++ src/V3Options.cpp
@@ -734,11 +734,7 @@ string V3Options::getenvBuiltins(const s
     }
 }
 
-#ifdef __FreeBSD__
 string V3Options::getenvMAKE() { return V3Os::getenvStr("MAKE", "gmake"); }
-#else
-string V3Options::getenvMAKE() { return V3Os::getenvStr("MAKE", "make"); }
-#endif
 
 string V3Options::getenvMAKEFLAGS() {  //
     return V3Os::getenvStr("MAKEFLAGS", "");
