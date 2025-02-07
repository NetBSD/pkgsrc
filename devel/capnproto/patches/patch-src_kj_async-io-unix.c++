$NetBSD: patch-src_kj_async-io-unix.c++,v 1.1 2025/02/07 13:19:30 riastradh Exp $

Teach capnproto how to get local socket peer identity on NetBSD.
Resolves:

   kj/async-io-test.c++:208: LocalPeerIdentity for unix socket had null UID
   stack:
   kj/async-io-test.c++:236: LocalPeerIdentity for unix socket had null UID
   stack:
   [ FAIL ] kj/async-io-test.c++:176: legacy test: AsyncIo/UnixSocket (335 μs)

--- src/kj/async-io-unix.c++.orig	2024-12-21 15:52:28.000000000 +0000
+++ src/kj/async-io-unix.c++
@@ -66,7 +66,7 @@
 #include <sys/ucred.h>
 #endif
 
-#if !defined(SOL_LOCAL) && (__FreeBSD__ || __DragonflyBSD__ || __APPLE__)
+#if !defined(SOL_LOCAL) && (__FreeBSD__ || __DragonflyBSD__ || __NetBSD__ || __APPLE__)
 // On DragonFly, FreeBSD < 12.2 and older Darwin you're supposed to use 0 for SOL_LOCAL.
 #define SOL_LOCAL 0
 #endif
@@ -1728,6 +1728,18 @@ kj::Own<PeerIdentity> SocketAddress::get
         result.pid = pid;
       }
 #endif
+
+#elif defined(LOCAL_PEEREID)
+      // The main public interface is getpeereid(3), but this is more
+      // convenient to slip in here without threading anything new
+      // through the AsyncIoStream abstraction.
+      struct unpcbid creds;
+      socklen_t length = sizeof(creds);
+      stream.getsockopt(SOL_LOCAL, LOCAL_PEEREID, &creds, &length);
+      KJ_ASSERT(length == sizeof(creds));
+      if (creds.unp_euid != static_cast<uid_t>(-1)) {
+        result.uid = creds.unp_euid;
+      }
 #endif
 
       return LocalPeerIdentity::newInstance(result);
