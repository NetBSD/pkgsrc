$NetBSD: patch-cmake_ConfigureChecks.cmake,v 1.1 2026/05/01 19:43:30 vins Exp $

Improve portability: Directly check for getprotobyname(3) instead of
guessing with OS-specific CPP macros.

--- cmake/ConfigureChecks.cmake.orig	2024-12-14 08:03:11.000000000 +0000
+++ cmake/ConfigureChecks.cmake
@@ -41,6 +41,11 @@ check_struct_has_member("struct sockaddr
 check_struct_has_member("struct sockaddr_storage" ss_family sys/socket.h HAVE_SOCKADDR_STORAGE)
 check_struct_has_member("struct stat" st_mtim.tv_nsec sys/stat.h HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC)
 
+include(CheckSymbolExists)
+if(HAVE_NETDB_H)
+  check_symbol_exists(getprotobyname "netdb.h" HAVE_GETPROTOBYNAME)
+endif()
+
 include(CheckCSourceCompiles)
 check_c_source_compiles("#include <net/if.h>
                          int main(void)
