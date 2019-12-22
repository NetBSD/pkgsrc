$NetBSD: patch-src_torrent_poll__kqueue.cc,v 1.3 2019/12/22 22:28:15 joerg Exp $

Add a cast so that this builds with the c++ in 8.0.
https://github.com/rakshasa/libtorrent/issues/159

--- src/torrent/poll_kqueue.cc.orig	2019-07-19 11:44:08.000000000 +0000
+++ src/torrent/poll_kqueue.cc
@@ -69,6 +69,15 @@ namespace torrent {
 
 #ifdef USE_KQUEUE
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+#if defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 999001500)
+#define LIBEV_UDATA(a) ((intptr_t)(a))
+#else
+#define LIBEV_UDATA(a) (a)
+#endif
+
 inline uint32_t
 PollKQueue::event_mask(Event* e) {
   assert(e->file_descriptor() != -1);
@@ -111,7 +120,7 @@ PollKQueue::modify(Event* event, unsigne
   struct kevent* itr = m_changes + (m_changedEvents++);
 
   assert(event == m_table[event->file_descriptor()].second);
-  EV_SET(itr, event->file_descriptor(), mask, op, 0, 0, event);
+  EV_SET(itr, event->file_descriptor(), mask, op, 0, 0, LIBEV_UDATA(event));
 }
 
 PollKQueue*
@@ -314,11 +323,11 @@ PollKQueue::close(Event* event) {
 
   // Shouldn't be needed anymore.
   for (struct kevent *itr = m_events, *last = m_events + m_waitingEvents; itr != last; ++itr)
-    if (itr->udata == event)
+    if (itr->udata == LIBEV_UDATA(event))
       itr->udata = NULL;
 
   m_changedEvents = std::remove_if(m_changes, m_changes + m_changedEvents,
-                                   rak::equal(event, rak::mem_ref(&kevent::udata))) - m_changes;
+                                   rak::equal(LIBEV_UDATA(event), rak::mem_ref(&kevent::udata))) - m_changes;
 }
 
 void
@@ -340,11 +349,11 @@ PollKQueue::closed(Event* event) {
 
   // Shouldn't be needed anymore.
   for (struct kevent *itr = m_events, *last = m_events + m_waitingEvents; itr != last; ++itr)
-    if (itr->udata == event)
+    if (itr->udata == LIBEV_UDATA(event))
       itr->udata = NULL;
 
   m_changedEvents = std::remove_if(m_changes, m_changes + m_changedEvents,
-                                   rak::equal(event, rak::mem_ref(&kevent::udata))) - m_changes;
+                                   rak::equal(LIBEV_UDATA(event), rak::mem_ref(&kevent::udata))) - m_changes;
 }
 
 // Use custom defines for EPOLL* to make the below code compile with
