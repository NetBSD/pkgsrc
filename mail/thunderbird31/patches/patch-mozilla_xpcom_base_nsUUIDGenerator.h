$NetBSD: patch-mozilla_xpcom_base_nsUUIDGenerator.h,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/xpcom/base/nsUUIDGenerator.h.orig	2014-07-18 00:05:57.000000000 +0000
+++ mozilla/xpcom/base/nsUUIDGenerator.h
@@ -27,7 +27,7 @@ private:
 protected:
 
     mozilla::Mutex mLock;
-#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(ANDROID)
+#if !defined(XP_WIN) && !defined(XP_MACOSX) && !defined(HAVE_ARC4RANDOM)
     char mState[128];
     char *mSavedState;
     uint8_t mRBytes;
