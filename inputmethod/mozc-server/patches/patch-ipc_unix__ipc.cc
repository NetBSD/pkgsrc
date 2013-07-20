$NetBSD: patch-ipc_unix__ipc.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- ipc/unix_ipc.cc.orig	2013-07-17 02:37:50.000000000 +0000
+++ ipc/unix_ipc.cc
@@ -28,7 +28,7 @@
 // OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 // skip all if non-Linux or Android.
-#if defined(OS_LINUX) && !defined(OS_ANDROID)
+#if defined(OS_LINUX) && !defined(OS_ANDROID) || defined(OS_NETBSD)
 
 #include "ipc/ipc.h"
 
@@ -127,7 +127,7 @@ bool IsPeerValid(int socket, pid_t *pid)
   // sometimes doesn't support the getsockopt(sock, SOL_SOCKET, SO_PEERCRED)
   // system call.
   // TODO(yusukes): Add implementation for ARM Linux.
-#ifndef __arm__
+#if !defined(__arm__) && !defined(OS_NETBSD)
   struct ucred peer_cred;
   int peer_cred_len = sizeof(peer_cred);
   if (getsockopt(socket, SOL_SOCKET, SO_PEERCRED,
@@ -143,7 +143,23 @@ bool IsPeerValid(int socket, pid_t *pid)
   }
 
   *pid = peer_cred.pid;
-#endif  // __arm__
+#endif  // __arm__, OS_NETBSD
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
