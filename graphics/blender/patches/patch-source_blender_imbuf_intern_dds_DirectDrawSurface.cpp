$NetBSD: patch-source_blender_imbuf_intern_dds_DirectDrawSurface.cpp,v 1.1 2016/07/16 03:45:19 markd Exp $

--- source/blender/imbuf/intern/dds/DirectDrawSurface.cpp.orig	2015-11-04 10:02:15.000000000 +0000
+++ source/blender/imbuf/intern/dds/DirectDrawSurface.cpp
@@ -55,12 +55,13 @@
 // FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 // OTHER DEALINGS IN THE SOFTWARE.
 
+// Include stdlib first to restore undefined min/max behavior w/ GCC 6
+#include <stdlib.h>  // malloc
 #include <DirectDrawSurface.h>
 #include <BlockDXT.h>
 #include <PixelFormat.h>
 
 #include <stdio.h> // printf
-#include <stdlib.h>  // malloc
 #include <math.h>  // sqrt
 #include <sys/types.h>
 
