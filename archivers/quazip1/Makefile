# $NetBSD: Makefile,v 1.3 2026/01/07 08:45:48 wiz Exp $

DISTNAME=	quazip-1.5
PKGNAME=	${DISTNAME:S/quazip/quazip1/}
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=stachenov/}
GITHUB_PROJECT=	quazip
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://stachenov.github.io/quazip/
COMMENT=	Qt/C++ wrapper for Minizip (v1.x)
LICENSE=	gnu-lgpl-v2.1 # with static linking exception

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE=		${CMAKE_BUILD_DIR}/quazip/quazip1-qt5.pc

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
