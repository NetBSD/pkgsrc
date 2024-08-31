$NetBSD: patch-ui_qt_utils_qt__ui__utils.cpp,v 1.1 2024/08/31 08:39:32 adam Exp $

Fix build.
https://gitlab.com/wireshark/wireshark/-/issues/20031

--- ui/qt/utils/qt_ui_utils.cpp.orig	2024-08-31 08:25:52.306338124 +0000
+++ ui/qt/utils/qt_ui_utils.cpp
@@ -246,7 +246,11 @@ void desktop_show_in_folder(const QStrin
     // If that failed, perhaps we are sandboxed.  Try using Portal Services.
     // https://flatpak.github.io/xdg-desktop-portal/docs/doc-org.freedesktop.portal.OpenURI.html
     if (!success) {
+#ifdef O_PATH
         const int fd = ws_open(QFile::encodeName(file_path), O_CLOEXEC | O_PATH, 0000);
+#else
+        const int fd = ws_open(QFile::encodeName(file_path), O_CLOEXEC, 0000);
+#endif
         if (fd != -1) {
             QDBusUnixFileDescriptor descriptor;
             descriptor.giveFileDescriptor(fd);
