$NetBSD: patch-patchlevel.h,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- patchlevel.h.orig	1994-05-19 02:01:21.000000000 +0000
+++ patchlevel.h
@@ -28,11 +28,11 @@
  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
-#ifndef lint
-static char rcsid_patchlevel_h[] = "patchlevel.h,v 2.0 1994/05/19 02:01:21 dan Exp";
+#if 0
+static char rcsid_patchlevel_h[] __attribute__((unused)) = "patchlevel.h,v 2.0 1994/05/19 02:01:21 dan Exp";
 #endif
 
 #define VERSION    "1.0"
-#define PATCHLEVEL "0"
+#define PATCHLEVEL "1"
 
 #endif
