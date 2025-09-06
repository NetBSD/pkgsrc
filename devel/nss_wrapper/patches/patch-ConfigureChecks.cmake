$NetBSD: patch-ConfigureChecks.cmake,v 1.1 2025/09/06 18:27:52 riastradh Exp $

Add NetBSD support.

--- ConfigureChecks.cmake.orig	2024-07-05 05:53:08.000000000 +0000
+++ ConfigureChecks.cmake
@@ -53,6 +53,7 @@ check_include_file(pwd.h HAVE_PWD_H)
 check_include_file(shadow.h HAVE_SHADOW_H)
 check_include_file(grp.h HAVE_GRP_H)
 check_include_file(nss.h HAVE_NSS_H)
+check_include_file(nsswitch.h HAVE_NSSWITCH_H)
 check_include_file(nss_common.h HAVE_NSS_COMMON_H)
 check_include_file(gnu/lib-names.h HAVE_GNU_LIB_NAMES_H)
 
@@ -74,11 +75,13 @@ check_function_exists(getgrent_r HAVE_GE
 
 check_function_exists(getgrouplist HAVE_GETGROUPLIST)
 
+if (NOT NETBSD)
 check_function_exists(gethostbyaddr_r HAVE_GETHOSTBYADDR_R)
 check_function_exists(gethostbyname_r HAVE_GETHOSTBYNAME_R)
 
 check_function_exists(gethostbyname2 HAVE_GETHOSTBYNAME2)
 check_function_exists(gethostbyname2_r HAVE_GETHOSTBYNAME2_R)
+endif (NOT NETBSD)
 
 check_function_exists(getprogname HAVE_GETPROGNAME)
 check_function_exists(getexecname HAVE_GETEXECNAME)
