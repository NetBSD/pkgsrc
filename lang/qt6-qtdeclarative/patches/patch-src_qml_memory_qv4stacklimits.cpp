$NetBSD: patch-src_qml_memory_qv4stacklimits.cpp,v 1.1 2023/04/14 19:57:59 nros Exp $

* Solaris uses pthread_attr_get_np for stack info

--- src/qml/memory/qv4stacklimits.cpp.orig	2023-04-14 19:04:28.043539627 +0000
+++ src/qml/memory/qv4stacklimits.cpp
@@ -235,7 +235,7 @@ StackProperties stackPropertiesGeneric(q
     pthread_t thread = pthread_self();
     pthread_attr_t sattr;
     pthread_attr_init(&sattr);
-#  if defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(Q_OS_NETBSD)
+#  if defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(Q_OS_NETBSD) || defined(Q_OS_SOLARIS)
     pthread_attr_get_np(thread, &sattr);
 #  else
     pthread_getattr_np(thread, &sattr);
