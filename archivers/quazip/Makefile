# $NetBSD: Makefile,v 1.26 2026/01/07 08:45:47 wiz Exp $

DISTNAME=	quazip-0.9
PKGREVISION=	23
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=stachenov/}
GITHUB_PROJECT=	quazip
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://stachenov.github.io/quazip/
COMMENT=	Qt/C++ wrapper for Minizip (v0)
LICENSE=	gnu-lgpl-v2.1 # with static linking exception

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE=		quazip.pc

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
