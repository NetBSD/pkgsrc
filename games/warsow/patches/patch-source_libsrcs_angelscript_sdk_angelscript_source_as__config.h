$NetBSD: patch-source_libsrcs_angelscript_sdk_angelscript_source_as__config.h,v 1.1 2025/09/29 13:31:28 nia Exp $

Add support for NetBSD to angelscript, so that it is not registered
as a "maximum portable" (heh) platform, which causes math functions
to not be exposed. Warsow needs the math function.

--- source/libsrcs/angelscript/sdk/angelscript/source/as_config.h.orig	2025-09-29 07:59:16.855149984 +0000
+++ source/libsrcs/angelscript/sdk/angelscript/source/as_config.h
@@ -872,7 +872,7 @@
 		#endif
 
 	// Free BSD
-	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__)
 		#define AS_BSD
 		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
 			#undef COMPLEX_MASK
