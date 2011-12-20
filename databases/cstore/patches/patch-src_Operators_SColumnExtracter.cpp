$NetBSD: patch-src_Operators_SColumnExtracter.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/Operators/SColumnExtracter.cpp.orig	2006-08-22 22:31:39.000000000 +0000
+++ src/Operators/SColumnExtracter.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "SColumnExtracter.h"
+#include <stdlib.h>
 
 SColumnExtracter::SColumnExtracter(string fileName, int c_index, int stringSize_, bool FORCE_REBUILD)
 {
