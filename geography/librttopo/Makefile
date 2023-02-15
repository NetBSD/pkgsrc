# $NetBSD: Makefile,v 1.1 2023/02/15 13:05:48 wiz Exp $

DISTNAME=	librttopo-1.1.0
CATEGORIES=	geography
MASTER_SITES=	https://git.osgeo.org/gitea/rttopo/librttopo/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.osgeo.org/gitea/rttopo/librttopo
COMMENT=	Create and manage standard (ISO 13249 aka SQL/MM) topologies
LICENSE=	gnu-gpl-v2 # or later

WRKSRC=		${WRKDIR}/librttopo

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
# doesn't test anything though
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	rttopo.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../geography/geos/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
