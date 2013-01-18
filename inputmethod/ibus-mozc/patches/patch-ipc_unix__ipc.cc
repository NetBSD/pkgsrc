$NetBSD: patch-ipc_unix__ipc.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- ipc/unix_ipc.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/unix_ipc.cc
@@ -28,7 +28,7 @@
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 // skip all if non-Linux or Android.
-#if defined(OS_LINUX) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_ANDROID)) || defined(OS_NETBSD)
 
 #include "ipc/ipc.h"
 
@@ -41,7 +41,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/un.h>
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
 #include <sys/ucred.h>
 #endif
 #include <sys/wait.h>
@@ -171,6 +171,22 @@ bool IsPeerValid(int socket, pid_t *pid)
 #endif  // __arm__
 #endif
 
+#if defined(OS_NETBSD)
+  struct unpcbid peer_cred;
+  int peer_cred_len = sizeof(peer_cred);
+  if (getsockopt(socket, 0, LOCAL_PEEREID,
+                 reinterpret_cast<void *>(&peer_cred),
+                 reinterpret_cast<socklen_t *>(&peer_cred_len)) < 0) {
+    LOG(ERROR) << "cannot get peer credential. Not a Unix socket?";
+    return false;
+  }
+
+  if (peer_cred.unp_euid!= ::geteuid()) {
+    LOG(WARNING) << "uid mismatch." << peer_cred.unp_euid << "!=" << ::geteuid();
+    return false;
+  }
+#endif
+
   return true;
 }
 
@@ -310,9 +326,11 @@ void IPCClient::Init(const string &name,
     address.sun_family = AF_UNIX;
     ::memcpy(address.sun_path, server_address.data(), server_address_length);
     address.sun_path[server_address_length] = '\0';
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX)
     address.sun_len = SUN_LEN(&address);
     const size_t sun_len = sizeof(address);
+#elif defined(OS_NETBSD)
+    size_t sun_len = SUN_LEN(&address);
 #else
     const size_t sun_len = sizeof(address.sun_family) + server_address_length;
 #endif
@@ -435,9 +453,11 @@ IPCServer::IPCServer(const string &name,
                SO_REUSEADDR,
                reinterpret_cast<char *>(&on),
                sizeof(on));
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX)
   addr.sun_len = SUN_LEN(&addr);
   const size_t sun_len = sizeof(addr);
+#elif defined(OS_NETBSD)
+  size_t sun_len = SUN_LEN(&addr);
 #else
   const size_t sun_len = sizeof(addr.sun_family) + server_address_.size();
 #endif
@@ -534,4 +554,4 @@ void IPCServer::Terminate() {
 
 };  // namespace mozc
 
-#endif  // OS_LINUX && !OS_ANDROID
+#endif  // (OS_LINUX && !OS_ANDROID) || OS_NETBSD
