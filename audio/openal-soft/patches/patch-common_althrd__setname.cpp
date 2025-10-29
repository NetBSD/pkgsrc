$NetBSD: patch-common_althrd__setname.cpp,v 1.1 2025/10/29 07:54:22 tnn Exp $

NetBSD 11.99.3 changed the pthread_setname_np(3) prototype.

--- common/althrd_setname.cpp.orig	2025-10-29 07:44:05.365440664 +0000
+++ common/althrd_setname.cpp
@@ -50,6 +50,7 @@ using setname_t1 = int(*)(const char*);
 using setname_t2 = int(*)(pthread_t, const char*);
 using setname_t3 = void(*)(pthread_t, const char*);
 using setname_t4 = int(*)(pthread_t, const char*, void*);
+using setname_t5 = int(*)(pthread_t, const char*, ...);
 
 [[maybe_unused]] void setname_caller(setname_t1 func, const char *name)
 { func(name); }
@@ -63,6 +64,9 @@ using setname_t4 = int(*)(pthread_t, con
 [[maybe_unused]] void setname_caller(setname_t4 func, const char *name)
 { func(pthread_self(), "%s", const_cast<char*>(name)); /* NOLINT(*-const-cast) */ }
 
+[[maybe_unused]] void setname_caller(setname_t5 func, const char *name)
+{ func(pthread_self(), "%s", const_cast<char*>(name)); }
+
 } // namespace
 
 void althrd_setname(const char *name [[maybe_unused]])
