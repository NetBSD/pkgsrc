# $NetBSD: Makefile,v 1.24 2026/09/02 19:03:45 wiz Exp $

DISTNAME=	libde265-1.1.1
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libde265
COMMENT=	Open h.265 video codec implementation
LICENSE=	gnu-lgpl-v3

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	libde265.pc.in

BUILDLINK_TRANSFORM+=	opt:-std=c++17:-std=gnu++17	# alloca

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
