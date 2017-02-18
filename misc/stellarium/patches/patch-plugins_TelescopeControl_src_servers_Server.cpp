$NetBSD: patch-plugins_TelescopeControl_src_servers_Server.cpp,v 1.1 2017/02/18 13:59:20 joerg Exp $

--- plugins/TelescopeControl/src/servers/Server.cpp.orig	2017-02-18 01:22:11.015702081 +0000
+++ plugins/TelescopeControl/src/servers/Server.cpp
@@ -22,6 +22,7 @@ along with this library; if not, write t
 Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
 */
 
+#include <sys/time.h>
 #include "Server.hpp"
 #include "Socket.hpp"
 //#include "Listener.hpp"
