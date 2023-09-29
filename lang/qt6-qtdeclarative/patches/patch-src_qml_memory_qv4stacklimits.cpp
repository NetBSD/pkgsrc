$NetBSD: patch-src_qml_memory_qv4stacklimits.cpp,v 1.2 2023/09/29 21:12:15 adam Exp $

Solaris uses pthread_attr_get_np for stack info.

--- src/qml/memory/qv4stacklimits.cpp.orig	2023-09-24 07:37:49.000000000 +0000
+++ src/qml/memory/qv4stacklimits.cpp
@@ -234,7 +234,7 @@ StackProperties stackPropertiesGeneric(q
 
     pthread_t thread = pthread_self();
     pthread_attr_t sattr;
-#  if defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(Q_OS_NETBSD)
+#  if defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(Q_OS_NETBSD) || defined(Q_OS_SOLARIS)
     pthread_attr_get_np(thread, &sattr);
 #  else
     pthread_getattr_np(thread, &sattr);
