# $NetBSD: Makefile,v 1.1.1.1 2008/12/13 06:58:01 minskim Exp $

DISTNAME=	silgraphite-2.3
PKGNAME=	${DISTNAME:S/silgraphite/silgraphite-ft/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=silgraphite/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://silgraphite.sourceforge.net/
COMMENT=	FreeType wrapper for SIL Graphite

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${DISTNAME}/wrappers/freetype

PKGCONFIG_OVERRIDE+=	silgraphite-ft.pc

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/silgraphite/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/silgraphite-ft.pc ${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
