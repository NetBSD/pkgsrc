$NetBSD: patch-plugins_in__serial_in__serial.c,v 1.1 2020/04/20 00:45:56 joerg Exp $

For B57600 and higher.

--- plugins/in_serial/in_serial.c.orig	2020-04-19 19:27:16.117063000 +0000
+++ plugins/in_serial/in_serial.c
@@ -17,6 +17,7 @@
  *  See the License for the specific language governing permissions and
  *  limitations under the License.
  */
+#define _NETBSD_SOURCE
 
 #include <fluent-bit/flb_info.h>
 #include <fluent-bit/flb_input.h>
