$NetBSD: patch-3rdparty_bx_include_bx_thread.h,v 1.2 2016/03/04 12:47:13 wiz Exp $

Adapt to calling convention on NetBSD.

--- 3rdparty/bx/include/bx/thread.h.orig	2016-02-24 07:02:17.000000000 +0000
+++ 3rdparty/bx/include/bx/thread.h
@@ -159,7 +159,11 @@ namespace bx
 			prctl(PR_SET_NAME,_name, 0, 0, 0);
 #	endif // defined(__GLIBC__) ...
 #elif BX_PLATFORM_BSD
+#ifdef __NetBSD__
+			pthread_setname_np(m_handle, "%s", (void *)_name);
+#else
 			pthread_setname_np(m_handle, _name);
+#endif
 #elif BX_PLATFORM_WINDOWS && BX_COMPILER_MSVC
 #	pragma pack(push, 8)
 			struct ThreadName
