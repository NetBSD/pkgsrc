$NetBSD: patch-Swiften_EventLoop_EventLoop.cpp,v 1.1 2014/04/26 11:41:46 wiz Exp $

Added missing lock_guard include.
Change-Id: I1ea6c42292b7c3b5f0ecdc1395b9c8e8cf17a6b9

http://swift.im/git/swift/commit/?h=swift-2.x&id=e4a3c018fe824c0c402dbc3167a113276fbe6e4e

--- Swiften/EventLoop/EventLoop.cpp.orig	2012-12-22 12:23:59.000000000 +0000
+++ Swiften/EventLoop/EventLoop.cpp
@@ -10,6 +10,7 @@
 #include <boost/bind.hpp>
 #include <iostream>
 #include <cassert>
+#include <boost/thread/locks.hpp>
 
 #include <Swiften/Base/Log.h>
 
