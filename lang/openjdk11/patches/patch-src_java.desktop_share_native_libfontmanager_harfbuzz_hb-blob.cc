$NetBSD: patch-src_java.desktop_share_native_libfontmanager_harfbuzz_hb-blob.cc,v 1.2 2021/02/01 15:51:55 ryoon Exp $

Completely remove _POSIX_C_SOURCE; with g++7 it causes errors about undeclared
symbols such as

In file included from /usr/pkg/gcc7/include/c++/math.h:36:0,
                 from /pkg_comp/obj/pkgsrc/lang/openjdk11/default/openjdk-jdk11u-jdk-11.0.5-10-1/src/java.desktop/share/native/libfontmanager/harfbuzz/hb.hh:171,
                 from /pkg_comp/obj/pkgsrc/lang/openjdk11/default/openjdk-jdk11u-jdk-11.0.5-10-1/src/java.desktop/share/native/libfontmanager/harfbuzz/hb-blob.cc:40:
/usr/pkg/gcc7/include/c++/cmath:1084:11: error: '::acosh' has not been declared 
   using ::acosh;
           ^~~~~ 

Very briefly: defining _POSIX_C_SOURCE only removes features, and therefore is
almost never the correct thing to do.

Filed upstream report to harfbuzz to patch this the same way:
https://github.com/harfbuzz/harfbuzz/issues/2084


--- src/java.desktop/share/native/libharfbuzz/hb-blob.cc.orig	2019-10-16 18:31:09.000000000 +0000
+++ src/java.desktop/share/native/libharfbuzz/hb-blob.cc
@@ -30,12 +30,6 @@
  * http://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html
  * https://www.oracle.com/technetwork/articles/servers-storage-dev/standardheaderfiles-453865.html
  */
-#ifndef _POSIX_C_SOURCE
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wunused-macros"
-#define _POSIX_C_SOURCE 200809L
-#pragma GCC diagnostic pop
-#endif
 
 #include "hb.hh"
 #include "hb-blob.hh"
