# $NetBSD: Makefile,v 1.26 2023/08/05 07:13:17 adam Exp $

DISTNAME=	googletest-1.14.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/google/googletest
COMMENT=	Google's C++ testing framework
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

CFLAGS+=	-fPIE
CXXFLAGS+=	-fPIE

PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest_main.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
