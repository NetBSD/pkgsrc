$NetBSD: patch-storage_ndb_src_kernel_blocks_trpman.cpp,v 1.1 2026/05/31 10:47:48 jnemeth Exp $

--- storage/ndb/src/kernel/blocks/trpman.cpp.orig	2026-05-25 04:00:24.695299691 +0000
+++ storage/ndb/src/kernel/blocks/trpman.cpp
@@ -23,6 +23,8 @@
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */
 
+#include <cmath>
+
 #include "trpman.hpp"
 #include "EventLogger.hpp"
 #include "TransporterRegistry.hpp"
