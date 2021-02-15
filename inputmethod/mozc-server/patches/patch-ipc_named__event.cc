$NetBSD: patch-ipc_named__event.cc,v 1.2 2021/02/15 14:50:23 ryoon Exp $

* sem_open(..., 0) is not supported for NetBSD at least.

--- ipc/named_event.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ ipc/named_event.cc
@@ -325,7 +325,7 @@ int NamedEventListener::WaitEventOrProce
 
 NamedEventNotifier::NamedEventNotifier(const char *name) : sem_(SEM_FAILED) {
   const std::string key_filename = NamedEventUtil::GetEventPath(name);
-  sem_ = ::sem_open(key_filename.c_str(), 0);
+  sem_ = ::sem_open(key_filename.c_str(), O_CREAT);
   if (sem_ == SEM_FAILED) {
     LOG(ERROR) << "sem_open failed: " << ::strerror(errno);
   }
