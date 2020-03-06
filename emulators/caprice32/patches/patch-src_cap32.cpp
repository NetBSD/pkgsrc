$NetBSD: patch-src_cap32.cpp,v 1.1 2020/03/06 12:23:01 nia Exp $

Fix paths.

--- src/cap32.cpp.orig	2019-01-04 19:01:29.000000000 +0000
+++ src/cap32.cpp
@@ -1578,7 +1578,7 @@ std::string getConfigurationFilename(boo
         configFilename = std::string(getenv("HOME")) + "/.cap32.cfg";
         // If still not found, look for cap32.cfg in /etc
         if (!forWrite && access(configFilename.c_str(), F_OK) != 0) {
-           configFilename = "/etc/cap32.cfg";
+           configFilename = "@PKG_SYSCONFDIR@/cap32.cfg";
         }
      }
   }
