$NetBSD: patch-external_liborcus_ExternalProject__liborcus.mk,v 1.1 2015/09/23 20:45:50 joerg Exp $

Pick up and apply some diffs based on

http://pkgs.fedoraproject.org/cgit/libreoffice.git/commit/?id=57cfb98d1c45259f946ff3444eeb6891a030e063

which makes libreoffice43 build with boost 1.59.

--- external/liborcus/ExternalProject_liborcus.mk.orig	2015-04-20 19:36:29.000000000 +0000
+++ external/liborcus/ExternalProject_liborcus.mk
@@ -70,7 +70,7 @@ liborcus_CPPFLAGS+=-D_GLIBCXX_DEBUG
 endif
 endif
 
-liborcus_CXXFLAGS=$(CXXFLAGS)
+liborcus_CXXFLAGS=$(CXXFLAGS) -DBOOST_SYSTEM_NO_DEPRECATED
 liborcus_LDFLAGS=$(LDFLAGS) $(gb_LTOFLAGS)
 ifeq ($(COM),MSC)
 liborcus_CXXFLAGS+=$(BOOST_CXXFLAGS)
