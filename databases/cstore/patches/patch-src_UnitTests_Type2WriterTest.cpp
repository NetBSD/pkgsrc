$NetBSD: patch-src_UnitTests_Type2WriterTest.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/UnitTests/Type2WriterTest.cpp.orig	2006-10-17 19:35:33.000000000 +0000
+++ src/UnitTests/Type2WriterTest.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "Type2WriterTest.h"
+#include <stdlib.h>
 
 Type2WriterTest::Type2WriterTest()
 {
