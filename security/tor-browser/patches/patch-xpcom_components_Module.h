$NetBSD: patch-xpcom_components_Module.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- xpcom/components/Module.h.orig	2016-01-21 05:38:42.000000000 +0000
+++ xpcom/components/Module.h
@@ -124,7 +124,7 @@ struct Module
 #    define NSMODULE_SECTION __declspec(allocate(".kPStaticModules$M"), dllexport)
 #  elif defined(__GNUC__)
 #    if defined(__ELF__)
-#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("protected")))
+#      define NSMODULE_SECTION __attribute__((section(".kPStaticModules"), visibility("default")))
 #    elif defined(__MACH__)
 #      define NSMODULE_SECTION __attribute__((section("__DATA, .kPStaticModules"), visibility("default")))
 #    elif defined (_WIN32)
