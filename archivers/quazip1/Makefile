# $NetBSD: Makefile,v 1.8 2026/11/07 19:11:17 wiz Exp $

DISTNAME=	quazip-1.7.2
PKGNAME=	${DISTNAME:S/quazip/quazip1/}
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=stachenov/}
GITHUB_PROJECT=	quazip
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://stachenov.github.io/quazip/
COMMENT=	Qt/C++ wrapper for Minizip (v1.x)
LICENSE=	gnu-lgpl-v2.1 # with static linking exception

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE=		${CMAKE_BUILD_DIR}/quazip/quazip1-qt6.pc

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
