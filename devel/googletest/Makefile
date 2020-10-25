# $NetBSD: Makefile,v 1.19 2020/10/25 12:59:26 nia Exp $

DISTNAME=	googletest-1.10.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/google/googletest
COMMENT=	Google's C++ testing framework
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

# cc1plus: error: unrecognized command line option "-std=c++11"
GCC_REQD+=		4.8

PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	googletest/cmake/gtest_main.pc.in

.include "../../mk/bsd.pkg.mk"
