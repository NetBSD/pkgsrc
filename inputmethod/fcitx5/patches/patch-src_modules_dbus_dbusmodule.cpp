$NetBSD: patch-src_modules_dbus_dbusmodule.cpp,v 1.1 2023/05/21 05:55:39 wiz Exp $

Fix fmt 10 compatibility
https://github.com/fcitx/fcitx5/commit/7fb3a5500270877d93b61b11b2a17b9b8f6a506b

--- src/modules/dbus/dbusmodule.cpp.orig	2021-01-25 16:03:44.057809000 +0000
+++ src/modules/dbus/dbusmodule.cpp
@@ -536,8 +536,9 @@ public:
                     ss << fmt::format("{:02x}", static_cast<int>(v));
                 }
                 ss << "] program:" << ic->program()
-                   << " frontend:" << ic->frontend()
-                   << " cap:" << fmt::format("{:x}", ic->capabilityFlags())
+                   << " frontend:" << ic->frontend() << " cap:"
+                   << fmt::format("{:x}",
+                                  static_cast<uint64_t>(ic->capabilityFlags()))
                    << " focus:" << ic->hasFocus() << std::endl;
                 return true;
             });
