$NetBSD: patch-core_libs_threads_actionthreadbase.cpp,v 1.1 2025/12/25 18:35:20 wiz Exp $

Add NetBSD support for setting thread name.

--- core/libs/threads/actionthreadbase.cpp.orig	2025-10-17 07:26:12.000000000 +0000
+++ core/libs/threads/actionthreadbase.cpp
@@ -260,9 +260,13 @@ void ActionThreadBase::setCurrentThreadN
 
     SetThreadDescription(GetCurrentThread(), reinterpret_cast<const wchar_t *>(name.utf16()));
 
+#elif defined(Q_OS_NETBSD)
+
+    pthread_setname_np(pthread_self(), "%s", (void*)name.toLatin1().constData());
+
 #else
 
-    qCWarning(DIGIKAM_GENERAL_LOG) << "Unsupported plateform to customize the current thread name.";
+    qCWarning(DIGIKAM_GENERAL_LOG) << "Unsupported platform to customize the current thread name.";
 
 #endif
 
