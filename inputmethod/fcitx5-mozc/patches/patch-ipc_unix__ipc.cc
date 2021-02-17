$NetBSD: patch-ipc_unix__ipc.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- ipc/unix_ipc.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ ipc/unix_ipc.cc
@@ -28,7 +28,7 @@
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 // OS_LINUX only. Note that OS_ANDROID/OS_WASM don't reach here.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 
 #include <arpa/inet.h>
 #include <fcntl.h>
@@ -125,7 +125,7 @@ bool IsPeerValid(int socket, pid_t *pid)
   // sometimes doesn't support the getsockopt(sock, SOL_SOCKET, SO_PEERCRED)
   // system call.
   // TODO(yusukes): Add implementation for ARM Linux.
-#ifndef __arm__
+#if !defined(__arm__) && !defined(OS_NETBSD)
   struct ucred peer_cred;
   int peer_cred_len = sizeof(peer_cred);
   if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED,
@@ -141,7 +141,23 @@ bool IsPeerValid(int socket, pid_t *pid)
   }
 
   *pid = peer_cred.pid;
-#endif  // __arm__
+#endif  // __arm__ || OS_NETBSD
+
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
 
   return true;
 }
@@ -468,4 +484,4 @@ void IPCServer::Terminate() { server_thr
 
 }  // namespace mozc
 
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
