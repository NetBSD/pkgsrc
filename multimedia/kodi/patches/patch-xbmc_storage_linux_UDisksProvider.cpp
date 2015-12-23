$NetBSD: patch-xbmc_storage_linux_UDisksProvider.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/storage/linux/UDisksProvider.cpp.orig	2015-12-22 18:21:00.000000000 +0000
+++ xbmc/storage/linux/UDisksProvider.cpp
@@ -17,6 +17,7 @@
  *  <http://www.gnu.org/licenses/>.
  *
  */
+#include <cstdlib>
 #include "UDisksProvider.h"
 #ifdef HAS_DBUS
 #include "settings/AdvancedSettings.h"
