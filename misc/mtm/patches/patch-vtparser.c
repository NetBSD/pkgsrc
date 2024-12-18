$NetBSD: patch-vtparser.c,v 1.1 2024/12/18 11:43:08 nia Exp $

Include <stdint.h> for WCHAR_MAX on some platforms (SunOS).

--- vtparser.c.orig	2024-12-18 11:41:09.250182180 +0000
+++ vtparser.c
@@ -25,6 +25,7 @@
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include <stdbool.h>
+#include <stdint.h>
 #include <string.h>
 #include "vtparser.h"
 
