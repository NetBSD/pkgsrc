$NetBSD: patch-xpcom_build_PoisonIOInterposer.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Replace XP_MACOSX with XP_DARWIN as the former is not defined when the
toolkit is not cocoa.

--- xpcom/build/PoisonIOInterposer.h.orig	2015-01-28 23:04:52.000000000 +0000
+++ xpcom/build/PoisonIOInterposer.h
@@ -26,7 +26,7 @@ void MozillaUnRegisterDebugFILE(FILE* aF
 
 MOZ_END_EXTERN_C
 
-#if defined(XP_WIN) || defined(XP_MACOSX)
+#if defined(XP_WIN) || defined(XP_DARWIN)
 
 #ifdef __cplusplus
 namespace mozilla {
@@ -44,7 +44,7 @@ bool IsDebugFile(intptr_t aFileID);
  */
 void InitPoisonIOInterposer();
 
-#ifdef XP_MACOSX
+#ifdef XP_DARWIN
 /**
  * Check that writes are dirty before reporting I/O (Mac OS X only)
  * This is necessary for late-write checks on Mac OS X, but reading the buffer
@@ -52,7 +52,7 @@ void InitPoisonIOInterposer();
  * to do this for everything else that uses
  */
 void OnlyReportDirtyWrites();
-#endif /* XP_MACOSX */
+#endif /* XP_DARWIN */
 
 /**
  * Clear IO poisoning, this is only safe to do on the main-thread when no other
@@ -63,19 +63,19 @@ void ClearPoisonIOInterposer();
 } // namespace mozilla
 #endif /* __cplusplus */
 
-#else /* XP_WIN || XP_MACOSX */
+#else /* XP_WIN || XP_DARWIN */
 
 #ifdef __cplusplus
 namespace mozilla {
 inline bool IsDebugFile(intptr_t aFileID) { return true; }
 inline void InitPoisonIOInterposer() {}
 inline void ClearPoisonIOInterposer() {}
-#ifdef XP_MACOSX
+#ifdef XP_DARWIN
 inline void OnlyReportDirtyWrites() {}
-#endif /* XP_MACOSX */
+#endif /* XP_DARWIN */
 } // namespace mozilla
 #endif /* __cplusplus */
 
-#endif /* XP_WIN || XP_MACOSX */
+#endif /* XP_WIN || XP_DARWIN */
 
 #endif // mozilla_PoisonIOInterposer_h
