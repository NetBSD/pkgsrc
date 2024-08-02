# $NetBSD: Makefile,v 1.28 2024/08/02 07:43:12 adam Exp $

DISTNAME=	googletest-1.15.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/google/googletest
COMMENT=	Google's C++ testing framework
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++

CFLAGS+=	-fPIE
CXXFLAGS+=	-fPIE

PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest_main.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
