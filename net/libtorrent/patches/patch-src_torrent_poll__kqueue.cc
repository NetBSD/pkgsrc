$NetBSD: patch-src_torrent_poll__kqueue.cc,v 1.1 2017/12/26 23:14:42 he Exp $

Add a cast so that this builds with the c++ in 8.0.

--- ./src/torrent/poll_kqueue.cc.orig	2015-08-08 15:01:32.000000000 +0000
+++ ./src/torrent/poll_kqueue.cc
@@ -111,7 +111,7 @@ PollKQueue::modify(Event* event, unsigne
   struct kevent* itr = m_changes + (m_changedEvents++);
 
   assert(event == m_table[event->file_descriptor()].second);
-  EV_SET(itr, event->file_descriptor(), mask, op, 0, 0, event);
+  EV_SET(itr, event->file_descriptor(), mask, op, 0, 0, (intptr_t)event);
 }
 
 PollKQueue*
