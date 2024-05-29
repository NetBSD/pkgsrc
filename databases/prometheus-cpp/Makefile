# $NetBSD: Makefile,v 1.6 2024/05/29 16:31:52 adam Exp $

DISTNAME=	prometheus-cpp-with-submodules
PKGNAME=	prometheus-cpp-1.1.0
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupp0r/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	prometheus-cpp
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupp0r/prometheus-cpp/
COMMENT=	Prometheus Client Library for Modern C++
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

PKGCONFIG_OVERRIDE+=	3rdparty/googletest/googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	3rdparty/googletest/googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	3rdparty/googletest/googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	3rdparty/googletest/googletest/cmake/gtest_main.pc.in
PKGCONFIG_OVERRIDE+=	cmake/prometheus-cpp-core.pc.in
PKGCONFIG_OVERRIDE+=	cmake/prometheus-cpp-pull.pc.in
PKGCONFIG_OVERRIDE+=	cmake/prometheus-cpp-push.pc.in

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
