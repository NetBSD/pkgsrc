$NetBSD: patch-src_UnitTests_IntReaderWriterTest.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/UnitTests/IntReaderWriterTest.cpp.orig	2006-10-17 19:35:33.000000000 +0000
+++ src/UnitTests/IntReaderWriterTest.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "IntReaderWriterTest.h"
+#include <stdlib.h>
 
 IntReaderWriterTest::IntReaderWriterTest()
 {
