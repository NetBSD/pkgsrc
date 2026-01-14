$NetBSD: patch-src_core_util_glob.cc,v 1.1 2026/01/14 17:20:16 ryoon Exp $

--- src/core/util/glob.cc.orig	2026-01-14 16:17:36.361039812 +0000
+++ src/core/util/glob.cc
@@ -12,6 +12,8 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
+#include <algorithm>
+
 #include "absl/strings/string_view.h"
 
 namespace grpc_core {
