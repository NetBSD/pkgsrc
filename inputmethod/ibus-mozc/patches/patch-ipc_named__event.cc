$NetBSD: patch-ipc_named__event.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

* sem_open(..., 0) is not supported for NetBSD at least.

--- ipc/named_event.cc.orig	2012-08-31 05:37:07.000000000 +0000
+++ ipc/named_event.cc
@@ -337,7 +337,7 @@ int NamedEventListener::WaitEventOrProce
 NamedEventNotifier::NamedEventNotifier(const char *name)
     : sem_(SEM_FAILED) {
   const string key_filename = NamedEventUtil::GetEventPath(name);
-  sem_ = ::sem_open(key_filename.c_str(), 0);
+  sem_ = ::sem_open(key_filename.c_str(), O_CREAT);
   if (sem_ == SEM_FAILED) {
     LOG(ERROR) << "sem_open failed: " << ::strerror(errno);
   }
