$NetBSD: patch-src_frontend_ibusfrontend_ibusfrontend.cpp,v 1.1 2021/03/01 11:13:20 mef Exp $

https://build.opensuse.org/package/view_file/M17N/fcitx5/fcitx5-gcc7.patch?expand=1

--- src/frontend/ibusfrontend/ibusfrontend.cpp.orig	2021-01-28 23:35:42.465005200 +0900
+++ src/frontend/ibusfrontend/ibusfrontend.cpp	2021-03-01 19:17:18.090095671 +0900
@@ -577,14 +577,23 @@ private:
         ([]() -> dbus::DBusStruct<uint32_t, uint32_t> {
             return {0, 0};
         }),
+#if __GNUC__ < 8
+        ([&](dbus::DBusStruct<uint32_t, uint32_t> type) {
+#else
         ([this](dbus::DBusStruct<uint32_t, uint32_t> type) {
+#endif
             setContentType(std::get<0>(type), std::get<1>(type));
         }),
         dbus::PropertyOption::Hidden);
     FCITX_OBJECT_VTABLE_WRITABLE_PROPERTY(
         clientCommitPreedit, "ClientCommitPreedit", "(b)",
+#if __GNUC__ < 8
+        ([&]() -> dbus::DBusStruct<bool> { return {clientCommitPreedit_}; }),
+        ([&](dbus::DBusStruct<bool> value) {
+#else
         ([this]() -> dbus::DBusStruct<bool> { return {clientCommitPreedit_}; }),
         ([this](dbus::DBusStruct<bool> value) {
+#endif
             clientCommitPreedit_ = std::get<0>(value);
         }),
         dbus::PropertyOption::Hidden);
