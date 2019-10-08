$NetBSD: patch-ext_em.cpp,v 1.1 2019/10/08 14:06:43 ryoon Exp $

* Fix build with recent NetBSD 9.99

--- ext/em.cpp.orig	2019-10-08 05:16:57.314742512 +0000
+++ ext/em.cpp
@@ -20,6 +20,10 @@ See the file COPYING for complete licens
 // THIS ENTIRE FILE WILL EVENTUALLY BE FOR UNIX BUILDS ONLY.
 //#ifdef OS_UNIX
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #include "project.h"
 
 /* The numer of max outstanding timers was once a const enum defined in em.h.
@@ -1507,7 +1511,7 @@ int EventMachine_t::DetachFD (EventableD
 	if (Poller == Poller_Kqueue) {
 		// remove any read/write events for this fd
 		struct kevent k;
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 		EV_SET (&k, ed->GetSocket(), EVFILT_READ | EVFILT_WRITE, EV_DELETE, 0, 0, (intptr_t)ed);
 #else
 		EV_SET (&k, ed->GetSocket(), EVFILT_READ | EVFILT_WRITE, EV_DELETE, 0, 0, ed);
@@ -1703,7 +1707,7 @@ void EventMachine_t::ArmKqueueWriter (Ev
 		if (!ed)
 			throw std::runtime_error ("added bad descriptor");
 		struct kevent k;
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 		EV_SET (&k, ed->GetSocket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, (intptr_t)ed);
 #else
 		EV_SET (&k, ed->GetSocket(), EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, ed);
@@ -1731,7 +1735,7 @@ void EventMachine_t::ArmKqueueReader (Ev
 		if (!ed)
 			throw std::runtime_error ("added bad descriptor");
 		struct kevent k;
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 		EV_SET (&k, ed->GetSocket(), EVFILT_READ, EV_ADD, 0, 0, (intptr_t)ed);
 #else
 		EV_SET (&k, ed->GetSocket(), EVFILT_READ, EV_ADD, 0, 0, ed);
@@ -1788,7 +1792,7 @@ void EventMachine_t::_AddNewDescriptors(
 			// INCOMPLETE. Some descriptors don't want to be readable.
 			assert (kqfd != -1);
 			struct kevent k;
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 			EV_SET (&k, ed->GetSocket(), EVFILT_READ, EV_ADD, 0, 0, (intptr_t)ed);
 #else
 			EV_SET (&k, ed->GetSocket(), EVFILT_READ, EV_ADD, 0, 0, ed);
