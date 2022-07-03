# $NetBSD: Makefile,v 1.21 2022/07/03 13:36:45 wiz Exp $

DISTNAME=	googletest-1.12.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/google/googletest
COMMENT=	Google's C++ testing framework
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11

# cc1plus: error: unrecognized command line option "-std=c++11"
GCC_REQD+=		4.8

CFLAGS+=		-fPIE
CXXFLAGS+=		-fPIE

PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest_main.pc.in

.include "../../mk/bsd.pkg.mk"
