$NetBSD: patch-src_socketengines_socketengine__kqueue.cpp,v 1.1 2019/05/03 17:14:28 nia Exp $

udata is intptr_t in NetBSD.

https://github.com/inspircd/inspircd/commit/0c992c5a3d6b30a6b14adf3181bf0b1e1fdeab48

--- src/socketengines/socketengine_kqueue.cpp.orig	2019-05-03 13:07:32.000000000 +0000
+++ src/socketengines/socketengine_kqueue.cpp
@@ -87,7 +87,11 @@ bool SocketEngine::AddFd(EventHandler* e
 
 	// We always want to read from the socket...
 	struct kevent* ke = GetChangeKE();
+#ifdef __NetBSD__
+	EV_SET(ke, fd, EVFILT_READ, EV_ADD, 0, 0, reinterpret_cast<intptr_t>(eh));
+#else
 	EV_SET(ke, fd, EVFILT_READ, EV_ADD, 0, 0, static_cast<void*>(eh));
+#endif
 
 	ServerInstance->Logs->Log("SOCKET", LOG_DEBUG, "New file descriptor: %d", fd);
 
@@ -128,7 +132,11 @@ void SocketEngine::OnSetEvent(EventHandl
 	{
 		// new poll-style write
 		struct kevent* ke = GetChangeKE();
+#ifdef __NetBSD__
+		EV_SET(ke, eh->GetFd(), EVFILT_WRITE, EV_ADD, 0, 0, reinterpret_cast<intptr_t>(eh));
+#else
 		EV_SET(ke, eh->GetFd(), EVFILT_WRITE, EV_ADD, 0, 0, static_cast<void*>(eh));
+#endif
 	}
 	else if ((old_mask & FD_WANT_POLL_WRITE) && !(new_mask & FD_WANT_POLL_WRITE))
 	{
@@ -139,7 +147,11 @@ void SocketEngine::OnSetEvent(EventHandl
 	if ((new_mask & (FD_WANT_FAST_WRITE | FD_WANT_SINGLE_WRITE)) && !(old_mask & (FD_WANT_FAST_WRITE | FD_WANT_SINGLE_WRITE)))
 	{
 		struct kevent* ke = GetChangeKE();
+#ifdef __NetBSD__
+		EV_SET(ke, eh->GetFd(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, reinterpret_cast<intptr_t>(eh));
+#else
 		EV_SET(ke, eh->GetFd(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, static_cast<void*>(eh));
+#endif
 	}
 }
 
@@ -161,7 +173,11 @@ int SocketEngine::DispatchEvents()
 	for (int j = 0; j < i; j++)
 	{
 		struct kevent& kev = ke_list[j];
+#ifdef __NetBSD__
+		EventHandler* eh = reinterpret_cast<EventHandler*>(kev.udata);
+#else
 		EventHandler* eh = static_cast<EventHandler*>(kev.udata);
+#endif
 		if (!eh)
 			continue;
 
