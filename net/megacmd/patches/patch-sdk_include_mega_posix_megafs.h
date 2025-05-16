$NetBSD: patch-sdk_include_mega_posix_megafs.h,v 1.3 2025/05/16 19:43:58 wiz Exp $

* Add Fallback classes to avoid inotify

--- sdk/include/mega/posix/megafs.h.orig	2025-04-02 09:16:59.000000000 +0200
+++ sdk/include/mega/posix/megafs.h
@@ -260,6 +260,29 @@ private:
 
 #endif // ENABLE_SYNC
 
+#elif defined(USE_PERIODIC)
+
+#define FSACCESS_CLASS FallbackFileSystemAccess
+
+class FallbackFileSystemAccess : public PosixFileSystemAccess
+{
+public:
+    DirNotify* newdirnotify(LocalNode& root,
+                            const LocalPath& rootPath,
+                            Waiter* waiter) override;
+
+    void addevents(Waiter*, int) override;
+
+    int checkevents(Waiter*) override;
+
+}; // class FallbackFileSystemAccess
+
+class FallbackDirNotify : public DirNotify
+{
+public:
+    FallbackDirNotify(const LocalPath& rootPath);
+};
+
 #endif // __linux__
 
 } // namespace
