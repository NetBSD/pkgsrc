$NetBSD: patch-libxorp_selector.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxorp/selector.cc.orig	2013-04-29 19:22:54.000000000 +0000
+++ libxorp/selector.cc
@@ -203,7 +203,7 @@ SelectorList::SelectorList(ClockBase *cl
     : _clock(clock), _observer(NULL), _testfds_n(0), _last_served_fd(-1),
       _last_served_sel(-1), _maxfd(0), _descriptor_count(0), _is_debug(false)
 {
-    static_assert(SEL_RD == (1 << SEL_RD_IDX) && SEL_WR == (1 << SEL_WR_IDX)
+    my_static_assert(SEL_RD == (1 << SEL_RD_IDX) && SEL_WR == (1 << SEL_WR_IDX)
 		  && SEL_EX == (1 << SEL_EX_IDX) && SEL_MAX_IDX == 3);
     for (int i = 0; i < SEL_MAX_IDX; i++)
 	FD_ZERO(&_fds[i]);
