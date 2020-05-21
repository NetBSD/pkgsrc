$NetBSD: patch-IlmBase_m4_threads.m4,v 1.1 2020/05/21 20:58:32 ryoon Exp $

* Improve POSIX shell portability.

--- IlmBase/m4/threads.m4.orig	2020-05-11 15:53:42.000000000 +0000
+++ IlmBase/m4/threads.m4
@@ -258,7 +258,7 @@ if test "${enable_posix_sem:-yes}" != "n
     AC_CHECK_HEADERS([semaphore.h], [
 	AC_SEARCH_LIBS(sem_init, [posix4 pthread], [
 	    AC_MSG_CHECKING([whether to use POSIX unnamed semaphores])
-		if test "${cross_compiling}" == "yes"; then
+		if test "${cross_compiling}" = "yes"; then
 			AC_LINK_IFELSE([
 			AC_LANG_PROGRAM([#include <semaphore.h>], [
 				sem_t mysem;
