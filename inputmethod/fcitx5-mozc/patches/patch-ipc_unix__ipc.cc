$NetBSD: patch-ipc_unix__ipc.cc,v 1.2 2024/02/10 12:26:02 ryoon Exp $

--- ipc/unix_ipc.cc.orig	2023-10-26 12:00:50.000000000 +0000
+++ ipc/unix_ipc.cc
@@ -28,7 +28,7 @@
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 // __linux__ only. Note that __ANDROID__/__wasm__ don't reach here.
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
 
 #include <fcntl.h>
 #include <sys/select.h>
@@ -119,6 +119,7 @@ bool IsWriteTimeout(int socket, absl::Du
 bool IsPeerValid(int socket, pid_t *pid) {
   *pid = 0;
 
+#if defined(__linux__)
   struct ucred peer_cred;
   int peer_cred_len = sizeof(peer_cred);
   if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED, &peer_cred,
@@ -133,7 +134,21 @@ bool IsPeerValid(int socket, pid_t *pid)
   }
 
   *pid = peer_cred.pid;
+#elif defined(__NetBSD__)
+  struct unpcbid peer_cred;
+  int peer_cred_len = sizeof(peer_cred);
+  if (getsockopt(socket, 0, LOCAL_PEEREID,
+                 reinterpret_cast<void *>(&peer_cred),
+                 reinterpret_cast<socklen_t *>(&peer_cred_len)) < 0) {
+    LOG(ERROR) << "cannot get peer credential. Not a Unix socket?";
+    return false;
+  }
 
+  if (peer_cred.unp_euid!= ::geteuid()) {
+    LOG(WARNING) << "uid mismatch." << peer_cred.unp_euid << "!=" << ::geteuid();
+    return false;
+  }
+#endif
   return true;
 }
 
