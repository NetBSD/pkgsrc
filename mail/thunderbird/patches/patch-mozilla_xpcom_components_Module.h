$NetBSD: patch-mozilla_xpcom_components_Module.h,v 1.1 2016/02/09 21:20:16 ryoon Exp $

--- mozilla/xpcom/components/Module.h.orig	2015-12-21 22:33:10.000000000 +0000
+++ mozilla/xpcom/components/Module.h
@@ -124,7 +124,7 @@ struct Module
 #    define NSMODULE_SECTION __declspec(allocate(".kPStaticModules$M"), dllexport)
 #  elif defined(__GNUC__)
 #    if defined(__ELF__)
-#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("protected")))
+#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("default")))
 #    elif defined(__MACH__)
 #      define NSMODULE_SECTION __attribute__((section("__DATA, .kPStaticModules"), visibility("default")))
 #    elif defined (_WIN32)
