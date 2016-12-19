$NetBSD: patch-inc_ucommon_thread.h,v 1.1 2016/12/19 13:33:43 joerg Exp $

Friendship is not inherited.

--- inc/ucommon/thread.h.orig	2016-12-18 09:48:45.932481633 +0000
+++ inc/ucommon/thread.h
@@ -1252,6 +1252,8 @@ class __EXPORT SharedPointer : protected
 {
 private:
     friend class shared_release;
+    template<class T> friend class shared_instance;
+
     SharedObject *pointer;
 
 protected:
