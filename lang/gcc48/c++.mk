# $NetBSD: c++.mk,v 1.1 2014/04/22 20:46:41 ryoon Exp $

# Objective C and Objective C++ enabled gcc should be built.
LANGS+=			c c++ objc obj-c++

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--with-gxx-include-dir=${GCC_PREFIX}/include/c++/
