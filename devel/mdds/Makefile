# $NetBSD: Makefile,v 1.57 2023/12/30 21:07:30 zafer Exp $

DISTNAME=	mdds-2.1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://kohei.us/files/mdds/src/
EXTRACT_SUFX=	.tar.bz2

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
