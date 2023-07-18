# $NetBSD: Makefile,v 1.24 2023/07/18 14:11:15 nia Exp $

DISTNAME=	googletest-1.13.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/google/googletest
COMMENT=	Google's C++ testing framework
LICENSE=	modified-bsd

# XXX check this and update it to use USE_CXX_FEATURES
# gcc7 is very high for a c++11 or c++14 baseline
USE_LANGUAGES=	c c++14

# cc1plus: error: unrecognized command line option "-std=c++11"
GCC_REQD+=	7

CFLAGS+=	-fPIE
CXXFLAGS+=	-fPIE

PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest_main.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
