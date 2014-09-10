$NetBSD: patch-src_timer.cc,v 1.1 2014/09/10 12:21:12 joerg Exp $

--- src/timer.cc.orig	2014-09-09 20:00:11.000000000 +0000
+++ src/timer.cc
@@ -33,12 +33,15 @@
     #include "autoconfig.h"
 #endif
 
+#include "singleton.h"
+
+class Timer;
+SINGLETON_MUTEX(Timer, true);
+
 #include "timer.h"
 
 using namespace zmm;
 
-SINGLETON_MUTEX(Timer, true);
-
 template <>
 Ref<Array<Timer::TimerSubscriberElement<TimerSubscriberSingleton<Object> > > > Timer::getAppropriateSubscribers<TimerSubscriberSingleton<Object> >()
 {
