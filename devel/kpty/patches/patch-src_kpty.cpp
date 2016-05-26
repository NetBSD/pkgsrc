$NetBSD: patch-src_kpty.cpp,v 1.1 2016/05/26 08:29:06 markd Exp $

NetBSD loginx() complains if ut_type not set before calling

--- src/kpty.cpp.orig	2016-04-03 21:01:19.000000000 +0000
+++ src/kpty.cpp
@@ -538,6 +538,9 @@ void KPty::login(const char *user, const
     l_struct.ut_time = time(0);
 # endif
 
+# if HAVE_STRUCT_UTMP_UT_TYPE
+    l_struct.ut_type = USER_PROCESS;
+# endif
 # if HAVE_LOGIN
 #  if HAVE_LOGINX
     ::loginx(&l_struct);
@@ -545,9 +548,6 @@ void KPty::login(const char *user, const
     ::login(&l_struct);
 #  endif
 # else
-#  if HAVE_STRUCT_UTMP_UT_TYPE
-    l_struct.ut_type = USER_PROCESS;
-#  endif
 #  if HAVE_STRUCT_UTMP_UT_PID
     l_struct.ut_pid = getpid();
 #   if HAVE_STRUCT_UTMP_UT_SESSION
