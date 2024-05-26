$NetBSD: patch-src_ConfigureChecks.cmake,v 1.1 2024/05/26 12:02:20 markd Exp $

NetBSD loginx() complains if ut_type not set before calling

--- src/ConfigureChecks.cmake.orig	2016-04-03 21:01:19.000000000 +0000
+++ src/ConfigureChecks.cmake
@@ -42,6 +42,7 @@ if (UNIX)
     endif (HAVE_UTMPX)
     if (login_in_libc OR login_in_libutil)
       set(HAVE_LOGIN 1)
+      check_struct_has_member("struct ${utmp}" "ut_type" "${utmp}.h" HAVE_STRUCT_UTMP_UT_TYPE)
     else (login_in_libc OR login_in_libutil)
       set(HAVE_LOGIN)
       check_struct_has_member("struct ${utmp}" "ut_type" "${utmp}.h" HAVE_STRUCT_UTMP_UT_TYPE)
