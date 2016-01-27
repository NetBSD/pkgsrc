$NetBSD: patch-3rdparty_bx_include_bx_thread.h,v 1.1 2016/01/27 13:59:19 wiz Exp $

Adapt to calling convention on NetBSD.

--- 3rdparty/bx/include/bx/thread.h.orig	2016-01-27 07:12:00.000000000 +0000
+++ 3rdparty/bx/include/bx/thread.h
@@ -150,7 +150,11 @@ namespace bx
 #if BX_PLATFORM_OSX || BX_PLATFORM_IOS
 			pthread_setname_np(_name);
 #elif (BX_PLATFORM_LINUX && defined(__GLIBC__)) || BX_PLATFORM_BSD
+#ifdef __NetBSD__
+			pthread_setname_np(m_handle, "%s", (void *)_name);
+#else
 			pthread_setname_np(m_handle, _name);
+#endif
 #elif BX_PLATFORM_WINDOWS && BX_COMPILER_MSVC
 #	pragma pack(push, 8)
 			struct ThreadName
