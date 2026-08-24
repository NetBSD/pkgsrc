# $NetBSD: Makefile,v 1.63 2026/08/24 08:42:15 adam Exp $

DISTNAME=	mdds-3.1.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/mdds/mdds
COMMENT=	Collection of multi-dimensional data structure and indexing algorithms
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	misc/mdds.pc.in

USE_CXX_FEATURES+=	c++17

BUILDLINK_DEPMETHOD.boost-headers?=	build
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
