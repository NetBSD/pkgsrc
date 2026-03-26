# $NetBSD: Makefile,v 1.15 2026/03/26 13:54:00 wiz Exp $

DISTNAME=	libde265-1.0.18
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libde265
COMMENT=	Open h.265 video codec implementation
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	libde265.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
