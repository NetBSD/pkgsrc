$NetBSD: patch-src_Operators_ColumnExtracter.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/Operators/ColumnExtracter.cpp.orig	2006-08-20 20:43:49.000000000 +0000
+++ src/Operators/ColumnExtracter.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "ColumnExtracter.h"
+#include <stdlib.h>
 
 ColumnExtracter::ColumnExtracter(string fileName, int c_index, bool FORCE_REBUILD)
 {
