$NetBSD: patch-xbmc_storage_linux_DeviceKitDisksProvider.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/storage/linux/DeviceKitDisksProvider.cpp.orig	2015-12-22 18:20:08.000000000 +0000
+++ xbmc/storage/linux/DeviceKitDisksProvider.cpp
@@ -17,6 +17,7 @@
  *  <http://www.gnu.org/licenses/>.
  *
  */
+#include <cstdlib>
 #include "DeviceKitDisksProvider.h"
 #ifdef HAS_DBUS
 #include "settings/AdvancedSettings.h"
