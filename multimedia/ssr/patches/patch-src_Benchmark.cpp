$NetBSD: patch-src_Benchmark.cpp,v 1.1 2016/03/01 20:11:35 joerg Exp $

--- src/Benchmark.cpp.orig	2016-03-01 13:00:19.000000000 +0000
+++ src/Benchmark.cpp
@@ -17,6 +17,7 @@ You should have received a copy of the G
 along with SimpleScreenRecorder.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <random>
 #include "Benchmark.h"
 
 #include "AVWrapper.h"
