$NetBSD: patch-src_UnitTests_NSEncodeDecode.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/UnitTests/NSEncodeDecode.cpp.orig	2006-10-17 19:35:33.000000000 +0000
+++ src/UnitTests/NSEncodeDecode.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include "NSEncodeDecode.h"
+#include <stdlib.h>
 
 NSEncodeDecode::NSEncodeDecode()
 {
