$NetBSD: patch-test_testdbus.cpp,v 1.1 2021/03/01 11:13:20 mef Exp $

https://build.opensuse.org/package/view_file/M17N/fcitx5/fcitx5-gcc7.patch?expand=1

--- fcitx5-5.0.3.orig/test/testdbus.cpp
+++ test/testdbus.cpp
@@ -67,7 +67,11 @@ private:
                                  []() { return 5; });
     FCITX_OBJECT_VTABLE_WRITABLE_PROPERTY(
         testProperty2, "testProperty2", "i", [this]() { return prop2; },
+#if __GNUC__  < 8
+        [&](int32_t v) { prop2 = v; });
+#else
         [this](int32_t v) { prop2 = v; });
+#endif
 };
 
 #define TEST_SERVICE "org.fcitx.Fcitx.TestDBus"
