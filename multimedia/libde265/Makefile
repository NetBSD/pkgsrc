# $NetBSD: Makefile,v 1.20 2026/05/24 18:08:08 wiz Exp $

DISTNAME=	libde265-1.0.19
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libde265
COMMENT=	Open h.265 video codec implementation
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
PKGCONFIG_OVERRIDE+=	libde265.pc.in

BUILDLINK_TRANSFORM+=	opt:-std=c++17:-std=gnu++17	# alloca

CMAKE_CONFIGURE_ARGS+=	-DENABLE_SDL=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
