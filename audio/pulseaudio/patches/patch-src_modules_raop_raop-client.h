$NetBSD: patch-src_modules_raop_raop-client.h,v 1.1 2018/06/19 02:25:58 maya Exp $

Missing headers for sockaddr_in (PR pkg/53381)

--- src/modules/raop/raop-client.h.orig	2017-09-05 09:33:13.000000000 +0000
+++ src/modules/raop/raop-client.h
@@ -20,6 +20,9 @@
   along with PulseAudio; if not, see <http://www.gnu.org/licenses/>.
 ***/
 
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 #include <pulse/volume.h>
 
 #include <pulsecore/core.h>
