# $NetBSD: Makefile,v 1.1 2026/04/15 07:58:19 kikadf Exp $

DISTNAME=	libscfg-0.2.0
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}/archive/
DISTFILES=	v${PKGVERSION_NOREV}${EXTRACT_SUFX}
DIST_SUBDIR=	libscfg

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://codeberg.org/emersion/libscfg
COMMENT=	C library for a simple configuration file format
LICENSE=	mit

USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/libscfg

PKGCONFIG_OVERRIDE_STAGE=	pre-build
PKGCONFIG_OVERRIDE=		output/meson-private/scfg.pc

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
